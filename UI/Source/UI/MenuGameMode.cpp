// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuGameMode.h"

#include "GamePlayerController.h"
#include "MenuHUD.h"
#include "MenuPlayerController.h"

void AMenuGameMode::SetPlayerController(TSubclassOf<APlayerController> PlayerController)
{
	PlayerControllerClass = PlayerController;
}

AMenuGameMode::AMenuGameMode()
{
	static ConstructorHelpers::FClassFinder<AMenuHUD> HUDObjectFinder(TEXT("Blueprint'/Game/Core/Widgets/WBP_MenuHUD'"));
	PlayerControllerClass = AGamePlayerController::StaticClass();
	//HUDClass = AMenuHUD::StaticClass();
	HUDClass = HUDObjectFinder.Class;
}
