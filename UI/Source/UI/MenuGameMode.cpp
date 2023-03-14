// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuGameMode.h"

#include "MenuHUD.h"
#include "MenuPlayerController.h"


AMenuGameMode::AMenuGameMode()
{
	static ConstructorHelpers::FClassFinder<AMenuHUD>
		HUDObjectFinder(TEXT("Blueprint'/Game/Core/Widgets/WBP_MenuHUD'"));
	PlayerControllerClass = AMenuPlayerController::StaticClass();
	HUDClass = HUDObjectFinder.Class;
}
