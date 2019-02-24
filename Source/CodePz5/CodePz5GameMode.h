// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CodePz5GameMode.generated.h"

DECLARE_EVENT(ACodePz5GameMode, FHudNeedsUpdate)

UCLASS(minimalapi)
class ACodePz5GameMode : public AGameModeBase
{
	GENERATED_BODY()

	int _Score;

public:
	ACodePz5GameMode();

	UFUNCTION()
	void OnTurretKilled(int ScoreChangeValue);

	int GetScore() { return _Score; };

	void ChangeScore(int ScoreDelta);

	FHudNeedsUpdate HudNeedsUpdate;
};



