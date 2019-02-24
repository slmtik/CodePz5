// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Turret.generated.h"

DECLARE_EVENT(ATurret, FOnTurretKilled)

UCLASS()
class CODEPZ5_API ATurret : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATurret();

	//Amount of scores awarded for kill this turret
	UPROPERTY(EditAnywhere, Category = TurretSettings)
	int32 ScoreForKill = 50.f;

	UPROPERTY(VisibleDefaultsOnly)
	UStaticMeshComponent* TurretBody;

	UPROPERTY(EditAnywhere, Category = TurretSettings)
	float BaseHealth = 100.f;

	float CurrentHealth;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void Destroyed() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FOnTurretKilled OnTurretKilled;

	UFUNCTION()
	void OnComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
private:

	//checking if turret is still alive
	void CheckHealth();
};
