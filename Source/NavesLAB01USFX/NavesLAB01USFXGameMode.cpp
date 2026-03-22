#include "NavesLAB01USFXGameMode.h"
#include "NavesLAB01USFXPawn.h"
#include "Enemigo.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"

// Asigna el Pawn del jugador por defecto al arrancar el juego
ANavesLAB01USFXGameMode::ANavesLAB01USFXGameMode()
{
    PrimaryActorTick.bCanEverTick = true;
    DefaultPawnClass = ANavesLAB01USFXPawn::StaticClass();
}

// Corre una sola vez al iniciar el nivel
// Spawna las 10 naves, obtiene al jugador e inicia los dos timers
void ANavesLAB01USFXGameMode::BeginPlay()
{
    Super::BeginPlay();

    UWorld* World = GetWorld();
    if (!World) return;

    // Spawnear las 10 naves en posiciones distribuidas
    // cada una con un pequeño offset en Y usando seno para que no salgan en línea recta
    for (int32 i = 0; i < 10; i++)
    {
        FVector UbicacionSpawn(-600 + (i * 50),
            150 + FMath::Sin(i) * 50,
            150);

        // SpawnActor crea una instancia del enemigo en el mundo
        AEnemigo* NuevaNave = World->SpawnActor<AEnemigo>(
            AEnemigo::StaticClass(),
            UbicacionSpawn,
            FRotator::ZeroRotator);

        if (NuevaNave)
        {
            NuevaNave->bMovimientoAutonomo = true; // Arrancan vagando solas
            AEnemigos.Add(NuevaNave);              // Guardar referencia para hablarles después
            UE_LOG(LogTemp, Warning, TEXT("Nave %d spawnada"), i);
        }
    }

    // Guardar referencia al jugador para calcular posiciones de formación
    PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0);
    if (PlayerPawn)
    {
        UltimaPosicionJugador = PlayerPawn->GetActorLocation(); // Guardar posición inicial
    }

    // Timer principal: intenta formar el avión cada 5 segundos, se repite solo
    GetWorldTimerManager().SetTimer(
        TimerFormacion,
        this,
        &ANavesLAB01USFXGameMode::FormarNavesFrentePawn,
        IntervaloFormacion,
        true);

    // Timer secundario: verifica el estado cada 0.5 segundos, se repite solo
    GetWorldTimerManager().SetTimer(
        TimerVerificarMovimiento,
        this,
        &ANavesLAB01USFXGameMode::VerificarMovimientoJugador,
        0.5f,
        true);
}

// Sin lógica adicional por ahora, disponible para uso futuro
void ANavesLAB01USFXGameMode::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

// Calcula las posiciones del avión frente al jugador y se las manda a cada nave
// Si la formación ya está activa no hace nada para no mover el destino mientras están quietas
void ANavesLAB01USFXGameMode::FormarNavesFrentePawn()
{
    if (!PlayerPawn || AEnemigos.Num() == 0) return;

    if (bFormacionActiva) return; // Si ya están formadas no molestar

    FVector  UbicacionPawn = PlayerPawn->GetActorLocation();
    FRotator RotacionPawn = PlayerPawn->GetActorRotation();
    FVector  DireccionFrente = RotacionPawn.Vector();

    // Poner el centro del avión 500 unidades delante del jugador
    FVector CentroAvion = UbicacionPawn + (DireccionFrente * -500);

    float E = EspaciadoVertical; // Alias corto para la escala

    // Posiciones relativas de cada parte del avión
    // X = adelante o atrás   Y = izquierda o derecha
    TArray<FVector> Offsets = {
        FVector(2.0f * E,  0.0f * E, 0.f),  // 0 - Nariz
        FVector(1.0f * E,  0.0f * E, 0.f),  // 1 - Fuselaje delantero
        FVector(0.0f * E,  0.0f * E, 0.f),  // 2 - Fuselaje centro
        FVector(0.0f * E, -2.0f * E, 0.f),  // 3 - Ala izquierda punta
        FVector(0.2f * E, -1.0f * E, 0.f),  // 4 - Ala izquierda media
        FVector(0.2f * E,  1.0f * E, 0.f),  // 5 - Ala derecha media
        FVector(0.0f * E,  2.0f * E, 0.f),  // 6 - Ala derecha punta
        FVector(-1.0f * E,  0.0f * E, 0.f),  // 7 - Fuselaje trasero
        FVector(-1.8f * E, -1.0f * E, 0.f),  // 8 - Cola izquierda
        FVector(-1.8f * E,  1.0f * E, 0.f),  // 9 - Cola derecha
    };

    for (int32 i = 0; i < AEnemigos.Num(); i++)
    {
        if (!AEnemigos[i]) continue;
        if (!Offsets.IsValidIndex(i)) continue;

        // Rotar el offset según la dirección del jugador
        // así el avión siempre apunta igual que él
        FVector OffsetRotado = RotacionPawn.RotateVector(Offsets[i]);
        FVector PosicionFormacion = CentroAvion + OffsetRotado;
        PosicionFormacion.Z = CentroAvion.Z; // Mantener misma altura

        AEnemigos[i]->PosicionDestinoGameMode = PosicionFormacion; // Mandar destino a la nave
        AEnemigos[i]->bMovimientoAutonomo = false;             // Parar movimiento autónomo
        AEnemigos[i]->SetActorRotation(FRotator(0, RotacionPawn.Yaw, 0)); // Misma rotación que el jugador
    }

    UE_LOG(LogTemp, Warning, TEXT("Formacion avion activada!"));
}

// Revisa si todas las naves están dentro de la tolerancia de su destino
// Retorna true solo si todas llegaron, si alguna falta retorna false
bool ANavesLAB01USFXGameMode::TodasLasNavesEnPosicion()
{
    for (AEnemigo* Nave : AEnemigos)
    {
        if (!Nave) continue;

        // Medir distancia entre donde está la nave y donde debería estar
        float Distancia = FVector::Dist(
            Nave->GetActorLocation(),
            Nave->PosicionDestinoGameMode);

        if (Distancia > ToleranciaLlegada) return false; // Esta nave aún no llegó
    }
    return true; // Todas llegaron a su posición
}

// Corre cada 0.5 segundos y tiene dos trabajos según el estado del juego
void ANavesLAB01USFXGameMode::VerificarMovimientoJugador()
{
    if (!PlayerPawn) return;

    FVector PosicionActual = PlayerPawn->GetActorLocation();

    // Trabajo 1: si la formación está activa, ver si el jugador se movió para romperla
    if (bFormacionActiva)
    {
        float DistanciaMovida = FVector::Dist(PosicionActual, UltimaPosicionJugador);

        if (DistanciaMovida > ToleranciaMovimiento)
        {
            bFormacionActiva = false; // Romper la formación

            // Todas las naves vuelven a vagar solas por el nivel
            for (AEnemigo* Nave : AEnemigos)
            {
                if (Nave)
                {
                    Nave->bMovimientoAutonomo = true;
                }
            }

            UltimaPosicionJugador = PosicionActual; // Actualizar posición del jugador
            UE_LOG(LogTemp, Warning, TEXT("Jugador se movio, formacion rota!"));
        }
        return;
    }

    // Trabajo 2: si no está formada, verificar si todas las naves ya llegaron a su posición
    if (!bFormacionActiva && AEnemigos.Num() > 0)
    {
        // Solo verificar si las naves están yendo a una posición asignada
        if (AEnemigos[0] && !AEnemigos[0]->bMovimientoAutonomo)
        {
            if (TodasLasNavesEnPosicion())
            {
                bFormacionActiva = true;           // Activar formación completa
                UltimaPosicionJugador = PosicionActual; // Guardar posición actual del jugador
                UE_LOG(LogTemp, Warning, TEXT("Todas las naves en posicion! Formacion completa."));
            }
        }
    }
}