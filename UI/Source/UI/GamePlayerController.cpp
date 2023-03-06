// Fill out your copyright notice in the Description page of Project Settings.


#include "GamePlayerController.h"

#include "MenuHUD.h"
#include "MenuPlayerController.h"

AGamePlayerController::AGamePlayerController(
const FObjectInitializer & Obj): Super(Obj)
{
	bShowMouseCursor = true;
	bEnableClickEvents = true;
}
void AGamePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	if (InputComponent)
	{
		InputComponent->BindKey(EKeys::LeftMouseButton, IE_Released,
		this, &AGamePlayerController::OnLeftMouseButtonUp);
		InputComponent->BindAction("ShowMaterialsPanel", IE_Pressed, this, &AGamePlayerController::ShowMaterialsPanel);
		InputComponent->BindAction("OpenMenu", IE_Pressed, this, &AGamePlayerController::OpenMenu);
		InputComponent->BindAction("Test", IE_Pressed, this, &AGamePlayerController::Test);
	}
}


void AGamePlayerController::OnLeftMouseButtonUp()
{
	if (OnMouseButtonUp.IsBound())
	{
		OnMouseButtonUp.Broadcast();
	}
}

void AGamePlayerController::ShowMaterialsPanel()
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
			IsMaterialsPanelOpened = !IsMaterialsPanelOpened;
			MenuHUD->RemoveDraggableMenu();
		}
	}
}

void AGamePlayerController::OpenMenu()
{
	if (AMenuHUD* MenuHUD = Cast<AMenuHUD>(GetHUD()))
	{
		MenuHUD->ShowMenu();
		TSubclassOf<APlayerController> PC = MenuHUD->GetMainGameInstance()->GamePlayerController;
		MenuHUD->GetMainGameInstance()->SetPlayerController(PC);
	}
}

void AGamePlayerController::Test()
{
	UE_LOG(LogTemp, Warning, TEXT("Game КОНТРОЛЛЕР"));
}