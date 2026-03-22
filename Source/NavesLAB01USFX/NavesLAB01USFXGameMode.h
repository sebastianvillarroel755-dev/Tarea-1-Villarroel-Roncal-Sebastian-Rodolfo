#pragma once
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "NavesLAB01USFXGameMode.generated.h"

class AEnemigo;
class APawn;

// GameMode del juego que hereda de AGameModeBase de Unreal, es el que controla todo como: spawna las naves, maneja los timers y decide cuándo formar o romper la silueta del avión
UCLASS(MinimalAPI)
class ANavesLAB01USFXGameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    ANavesLAB01USFXGameMode(); // Asigna el Pawn del jugador por defecto

    virtual void BeginPlay() override; // Spawna las 10 naves e inicia los timers
    virtual void Tick(float DeltaTime) override; // Disponible para lógica futura

public:
    TArray<AEnemigo*> AEnemigos; // Lista con las 10 naves para poder hablarles individualmente

    FTimerHandle TimerFormacion;           // Timer que intenta formar el avión cada 5 segundos
    FTimerHandle TimerVerificarMovimiento; // Timer que revisa el estado cada 0.5 segundos

    void FormarNavesFrentePawn();      // Calcula las posiciones del avión y se las manda a cada nave
    void VerificarMovimientoJugador(); // Revisa si todas llegaron o si el jugador se movió para romper la formación
    bool TodasLasNavesEnPosicion();    // Retorna true solo si todas las naves llegaron a su posición

    APawn* PlayerPawn; // Referencia al jugador para calcular dónde va el centro del avión

    float IntervaloFormacion = 5.0f;  // Cada cuántos segundos se intenta activar la formación

    float EspaciadoVertical = 100.0f; // Tamaño general de la formación, a mayor valor el avión es más grande

    bool bFormacionActiva = false; // true = todas llegaron y están quietas, false = en movimiento o yendo a posición

    FVector UltimaPosicionJugador; // Guarda la posición anterior del jugador para comparar si se movió

    float ToleranciaMovimiento = 50.0f; // Distancia mínima que debe moverse el jugador para romper la formación

    float ToleranciaLlegada = 40.0f; // Distancia mínima para considerar que una nave llegó a su posición
};