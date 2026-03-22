#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemigo.generated.h"

class UStaticMeshComponent;

// Clase del enemigo que hereda de Actor que es la clase base de Unreal
// Se mueve solo por el nivel con waypoints aleatorios
UCLASS()
class NAVESLAB01USFX_API AEnemigo : public AActor
{
    GENERATED_BODY()

public:
    AEnemigo(); // Arma la nave con su malla y valores iniciales

    UStaticMeshComponent* MallaEnemigo; // La figura 3D del enemigo que se ve en el nivel

    UPROPERTY(EditAnywhere, Category = "Enemigo")
        float VelocidadMovimiento = 100.0f; // Qué tan rápido se mueve en cm por segundo

    UPROPERTY(EditAnywhere, Category = "Enemigo")
        FVector WorldLimitesMin = FVector(-1000, -1000, 0); // Límite inferior del área donde genera sus waypoints

    UPROPERTY(EditAnywhere, Category = "Enemigo")
        FVector WorldLimitesMax = FVector(1000, 1000, 0); // Límite superior del área donde genera sus waypoints

    UPROPERTY(EditAnywhere, Category = "Formacion")
        int32 IndiceFormacion = 0; // Número del 0 al 9 que dice qué parte del avión le toca a este enemigo

    UPROPERTY(EditAnywhere, Category = "Formacion")
        FVector CentroFormacion = FVector(0, 0, 200); // Punto central del avión, los offsets se calculan desde aquí

    UPROPERTY(EditAnywhere, Category = "Formacion")
        bool bEnFormacion = false; // true = va a su posición en el avión, false = vaga libre por el nivel

    UPROPERTY(EditAnywhere, Category = "Formacion")
        float EscalaFormacion = 150.0f; // Tamaño de la formación, a mayor valor más separadas las naves

    bool bMovimientoAutonomo = false; // true = recorre sus waypoints solo, false = el GameMode lo dirige

    FVector PosicionDestinoGameMode; // Destino que le manda el GameMode cuando no es autónomo

    void ActivarFormacion(FVector Centro, float Escala); // El GameMode llama esto para mandarlo a su posición en el avion
    void DesactivarFormacion(); // Rompe la formación y vuelve a moverse solo

protected:
    virtual void BeginPlay() override; // Genera los waypoints aleatorios al iniciar el nivel

public:
    virtual void Tick(float DeltaTime) override; // Lógica de movimiento que se ejecuta cada frame

private:
    TArray<FVector> PuntosRuta;      // Los 10 waypoints aleatorios que recorre en circuito
    int32 IndicePuntoRutaActual = 0; // En qué waypoint va actualmente, vuelve a 0 al terminar el circuito
    FVector PosicionInicial;         // Donde apareció la nave, es el primer punto de la ruta
    float Tolerancia = 50.0f;        // Distancia mínima para considerar que llegó a un waypoint o destino
    float TiempoAcumulado = 0.0f;    // Acumula tiempo cada frame, disponible para uso futuro

    FVector ObtenerPosicionEnFormacion(); // Calcula dónde exactamente debe ir según su índice en el avión
};