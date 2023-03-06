// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGameInstance.h"

#include "GamePlayerController.h"
#include "MenuGameMode.h"
#include "MenuPlayerController.h"
#include "SWarningOrErrorBox.h"
#include "Blueprint/UserWidget.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/Engine.h"
#include "Kismet/GameplayStatics.h"


UMainGameInstance::UMainGameInstance(const FObjectInitializer& ObjectInitializer)
{
	
}

void UMainGameInstance::SetPlayerController(TSubclassOf<APlayerController> PlayerController)
{
	AMenuPlayerController* newMenuPC;
	AGamePlayerController* newGamePC;
	if (Cast<AMenuPlayerController>(PlayerController))
	{
		newMenuPC = NewObject<AMenuPlayerController>(this, MenuPlayerController->StaticClass());
		GetWorld()->GetAuthGameMode()->SwapPlayerControllers(GetFirstLocalPlayerController(), newMenuPC);
	}
	else
	{
		newGamePC = NewObject<AGamePlayerController>(this, GamePlayerController->StaticClass());
		GetWorld()->GetAuthGameMode()->SwapPlayerControllers(GetFirstLocalPlayerController(), newGamePC);
	}
}

void UMainGameInstance::Init()
{

}


void UMainGameInstance::OnStart()
{
	Super::OnStart();
}
