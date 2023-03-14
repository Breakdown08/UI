// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuPlayerController.h"

#include "MenuHUD.h"

AMenuPlayerController::AMenuPlayerController(
const FObjectInitializer & Obj): Super(Obj)
{
	bShowMouseCursor = true;
	bEnableClickEvents = true;
}

void AMenuPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	if (InputComponent)
	{
		InputComponent->BindAction("ShowMaterialsPanel", IE_Pressed, this, &AMenuPlayerController::ShowMaterialsPanel);
		InputComponent->BindAction("OpenMenu", IE_Pressed, this, &AMenuPlayerController::OpenMenu);
		InputComponent->BindAction("Test", IE_Pressed, this, &AMenuPlayerController::Test);
	}
}

void AMenuPlayerController::OnLeftMouseButtonUp()
{
	if (OnMouseButtonUp.IsBound())
	{
		OnMouseButtonUp.Broadcast();
	}
}

void AMenuPlayerController::ShowMaterialsPanel()
{
	if (!IsMaterialsPanelOpened)
	{
		if (AMenuHUD* MenuHUD = Cast<AMenuHUD>(GetHUD()))
		{
			MenuHUD->ShowDraggableMenu();
		}
	}
	else
	{
		if (AMenuHUD* MenuHUD = Cast<AMenuHUD>(GetHUD()))
		{
			MenuHUD->RemoveDraggableMenu();
		}
	}
	IsMaterialsPanelOpened = !IsMaterialsPanelOpened;
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
	UE_LOG(LogTemp, Warning, TEXT("ТЕСТ КНОПКА"));
}
