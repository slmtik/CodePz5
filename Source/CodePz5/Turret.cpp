// Fill out your copyright notice in the Description page of Project Settings.

#include "Turret.h"
#include "CodePz5Projectile.h"

// Sets default values
ATurret::ATurret()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TurretBody = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	RootComponent = TurretBody;
	TurretBody->OnComponentHit.AddDynamic(this, &ATurret::OnComponentHit);
}

// Called when the game starts or when spawned
void ATurret::BeginPlay()
{
	Super::BeginPlay();

	CurrentHealth = BaseHealth;
}

void ATurret::Destroyed()
{
	Super::Destroyed();

	if (OnTurretKilled.IsBound())
	{
		OnTurretKilled.Broadcast();
	}
}

// Called every frame
void ATurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATurret::OnComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	ACodePz5Projectile* projectile = Cast<ACodePz5Projectile>(OtherActor);
	if (projectile)
	{
		CurrentHealth -= projectile->Damage;

		CheckHealth();
	}
}

void ATurret::CheckHealth()
{
	if (CurrentHealth <= 0)
		Destroy();
}

