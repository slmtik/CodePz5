// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "CodePz5GameMode.h"
#include "CodePz5HUD.h"
#include "CodePz5Character.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "Turret.h"

ACodePz5GameMode::ACodePz5GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ACodePz5HUD::StaticClass();

	TArray<AActor*> turretActors;
	UGameplayStatics::GetAllActorsOfClass(this, ATurret::StaticClass(), turretActors);
	for (AActor* turretActor : turretActors)
	{
		ATurret* turret = Cast<ATurret>(turretActor);
		if (turret)
		{
			turret->OnTurretKilled.AddUFunction(this, "OnTurretKilled", turret->ScoreForKill);
		}
	}
}

void ACodePz5GameMode::OnTurretKilled(int ScoreForKill)
{
	ChangeScore(ScoreForKill);
}

void ACodePz5GameMode::ChangeScore(int ScoreDelta)
{
	_Score += ScoreDelta;

	if (HudNeedsUpdate.IsBound())
	{
		HudNeedsUpdate.Broadcast();
	}
}
