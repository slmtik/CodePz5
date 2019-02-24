// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TextBlock.h"
#include "MyUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class CODEPZ5_API UMyUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* ScoreText;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* Notification;

	UFUNCTION(BlueprintPure)
	float GetScore();

	void SetScoreText(float ScoreValue);
	void ShowNotification();

	UFUNCTION()
	void UpdateScoreHud();
};
