// Fill out your copyright notice in the Description page of Project Settings.

#include "MyUserWidget.h"
#include "CodePz5GameMode.h"
#include "Turret.h"
#include "Kismet/GameplayStatics.h"

void UMyUserWidget::NativeConstruct()
{

	SetScoreText(GetScore());

	if (Notification)
	{
		Notification->SetText(FText::FromString("You have killed the turret."));
		Notification->SetVisibility(ESlateVisibility::Hidden);
	}

	ACodePz5GameMode* gm = Cast<ACodePz5GameMode>(GetWorld()->GetAuthGameMode());

	if (gm)
	{
		gm->HudNeedsUpdate.AddUFunction(this, "UpdateScoreHud");
	}
}

float UMyUserWidget::GetScore()
{
	ACodePz5GameMode* gm = Cast<ACodePz5GameMode>(GetWorld()->GetAuthGameMode());

	if (gm)
	{
		return gm->GetScore();
	}
	return 0;
}

void UMyUserWidget::SetScoreText(float ScoreValue)
{
	if (ScoreText)
	{
		ScoreText->SetText(FText::FromString("Your score is " + FString::FromInt(ScoreValue)));
	}
}

void UMyUserWidget::ShowNotification()
{
	if (Notification)
	{
		Notification->SetVisibility(ESlateVisibility::Visible);
		FTimerHandle handle;
		GetWorld()->GetTimerManager().SetTimer(handle, [this] {
			Notification->SetVisibility(ESlateVisibility::Hidden);
		}, 2, 1);

	}
}

void UMyUserWidget::UpdateScoreHud()
{
	SetScoreText(GetScore());
	ShowNotification();
}
