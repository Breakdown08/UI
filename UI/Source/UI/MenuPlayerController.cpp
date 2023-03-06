// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuPlayerController.h"

#include "MenuHUD.h"

AMenuPlayerController::AMenuPlayerController()
{
}

void AMenuPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	if (InputComponent)
	{
		InputComponent->BindAction("OpenMenu", IE_Pressed, this, &AMenuPlayerController::OpenMenu);
		InputComponent->BindAction("Test", IE_Pressed, this, &AMenuPlayerController::Test);
	}
}

void AMenuPlayerController::OpenMenu()
{
	if (AMenuHUD* MenuHUD = Cast<AMenuHUD>(GetHUD()))
	{
		MenuHUD->ShowMenu();
	}
}

void AMenuPlayerController::Test()
{
	UE_LOG(LogTemp, Warning, TEXT("МЕНЮ КОНТРОЛЛЕР"));
}
