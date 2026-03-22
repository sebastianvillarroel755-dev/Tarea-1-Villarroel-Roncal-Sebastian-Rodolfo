#include "Enemigo.h"
#include "Components/StaticMeshComponent.h"

// Se crea el enemigo con su figura y se activa para que se mueva
AEnemigo::AEnemigo()
{
    PrimaryActorTick.bCanEverTick = true;

    // Crear el componente visual y ponerlo como raíz del actor
    MallaEnemigo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaEnemigo"));
    RootComponent = MallaEnemigo;

    // Buscar la malla Shape_Torus en el StarterContent y asignarla automáticamente
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MallaAsset(
        TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Torus.Shape_Torus'"));
    if (MallaAsset.Succeeded())
    {
        MallaEnemigo->SetStaticMesh(MallaAsset.Object);
    }
}

// Corre una sola vez al iniciar el nivel
// Guarda dónde apareció y genera 10 puntos aleatorios para recorrer
void AEnemigo::BeginPlay()
{
    Super::BeginPlay();

    PosicionInicial = GetActorLocation(); // Guardar posición de spawn

    // Armar la lista de waypoints empezando desde donde apareció
    PuntosRuta.Empty();
    PuntosRuta.Add(PosicionInicial);

    // Generar 10 puntos aleatorios dentro del área definida por los límites
    for (int32 i = 0; i < 10; i++)
    {
        float X = FMath::RandRange(WorldLimitesMin.X, WorldLimitesMax.X);
        float Y = FMath::RandRange(WorldLimitesMin.Y, WorldLimitesMax.Y);
        FVector NuevoPuntoRuta(X, Y, PosicionInicial.Z); // Misma altura siempre
        PuntosRuta.Add(NuevoPuntoRuta);
    }

    IndicePuntoRutaActual = 1; // Arrancar desde el segundo punto de la lista
}

// Se ejecuta cada frame, tiene 3 modos de movimiento según el estado actual
void AEnemigo::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Modo 1: formación activa, va directo a su posición en el avión
    if (bEnFormacion)
    {
        FVector Destino = ObtenerPosicionEnFormacion();
        FVector Actual = GetActorLocation();
        float   Distancia = FVector::Dist(Actual, Destino);

        if (Distancia > Tolerancia)
        {
            // Avanzar en línea recta hacia su posición en el avión
            FVector Direccion = (Destino - Actual).GetSafeNormal();
            FVector NuevaUbicacion = Actual + (Direccion * VelocidadMovimiento * DeltaTime);
            SetActorLocation(NuevaUbicacion);
        }
        // Si ya llegó se queda quieto en esa posición
        return; // No ejecutar los otros modos
    }

    // Modo 2: el GameMode le dijo a dónde ir, sigue ese destino
    if (!bMovimientoAutonomo)
    {
        FVector PosicionActual = GetActorLocation();
        float Distancia = FVector::Dist(PosicionActual, PosicionDestinoGameMode);

        if (Distancia <= Tolerancia)
        {
            return; // Ya llegó, espera nueva instrucción del GameMode
        }
        else
        {
            // Moverse en línea recta hacia el destino que mandó el GameMode
            FVector Direccion = (PosicionDestinoGameMode - PosicionActual).GetSafeNormal();
            FVector NuevaUbicacion = PosicionActual + (Direccion * VelocidadMovimiento * DeltaTime);
            SetActorLocation(NuevaUbicacion);
        }
    }
    // Modo 3: movimiento autónomo, recorre sus waypoints en circuito
    else if (PuntosRuta.Num() > 1)
    {
        FVector UbicacionActual = GetActorLocation();
        FVector UbicacionDestino = PuntosRuta[IndicePuntoRutaActual];
        float   Distancia = FVector::Dist(UbicacionActual, UbicacionDestino);

        if (Distancia <= Tolerancia)
        {
            // Llegó al waypoint actual, pasar al siguiente
            IndicePuntoRutaActual++;
            if (IndicePuntoRutaActual >= PuntosRuta.Num())
            {
                IndicePuntoRutaActual = 0; // Volver al inicio del circuito
            }
        }
        else
        {
            // Avanzar hacia el waypoint actual
            FVector Direccion = (UbicacionDestino - UbicacionActual).GetSafeNormal();
            FVector NuevaUbicacion = UbicacionActual + (Direccion * VelocidadMovimiento * DeltaTime);
            SetActorLocation(NuevaUbicacion);
        }
    }
}

// El GameMode llama esto para activar la formación y decirle dónde es el centro del avión
void AEnemigo::ActivarFormacion(FVector Centro, float Escala)
{
    CentroFormacion = Centro; // Guardar el centro del avión en el mundo
    EscalaFormacion = Escala; // Guardar el tamaño de la formación
    bEnFormacion = true;   // Activar modo formación
}

// Rompe la formación, la nave vuelve a recorrer sus waypoints solos
void AEnemigo::DesactivarFormacion()
{
    bEnFormacion = false; // Con esto solo ya retoma el movimiento autónomo
}

// Calcula la posición exacta en el mundo que le toca a este enemigo en el avión
// Usa una tabla de offsets relativos al centro, uno por cada parte del avión
FVector AEnemigo::ObtenerPosicionEnFormacion()
{
    // Cada offset es la posición relativa de una parte del avión
    // X = adelante o atrás    Y = izquierda o derecha
    // Se multiplican por EscalaFormacion para el tamaño real
    TArray<FVector> Offsets = {
        FVector(2.0f,  0.0f, 0.f),  // 0 - Nariz
        FVector(1.0f,  0.0f, 0.f),  // 1 - Fuselaje delantero
        FVector(0.0f,  0.0f, 0.f),  // 2 - Fuselaje centro
        FVector(0.0f, -2.0f, 0.f),  // 3 - Ala izquierda punta
        FVector(0.2f, -1.0f, 0.f),  // 4 - Ala izquierda media
        FVector(0.2f,  1.0f, 0.f),  // 5 - Ala derecha media
        FVector(0.0f,  2.0f, 0.f),  // 6 - Ala derecha punta
        FVector(-1.0f,  0.0f, 0.f),  // 7 - Fuselaje trasero
        FVector(-1.3f, -0.5f, 0.f),  // 8 - Cola izquierda
        FVector(-1.3f,  0.5f, 0.f),  // 9 - Cola derecha
    };

    // Si el índice no existe por alguna razón, ir al centro del avión
    if (!Offsets.IsValidIndex(IndiceFormacion))
    {
        return CentroFormacion;
    }

    // Posición final = centro del avión + offset de su parte multiplicado por la escala
    return CentroFormacion + (Offsets[IndiceFormacion] * EscalaFormacion);
}