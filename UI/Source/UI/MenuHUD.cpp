// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuHUD.h"

#include "SDraggableWidget.h"
#include "SMenuWidget.h"
#include "Kismet/GameplayStatics.h"

void AMenuHUD::BeginPlay()
{
	Super::BeginPlay();
	ShowMenu();
}

AMenuHUD::AMenuHUD()
{

}


void AMenuHUD::ShowMenu()
{
	if (GEngine && GEngine->GameViewport)
	{
		MenuWidget = SNew(SMenuWidget)
		//.Style(&WidgetStyle)
		.OwningHUD(this);
		GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(MenuWidgetContainer, SWeakWidget).PossiblyNullContent(MenuWidget.ToSharedRef()));

		if (PlayerOwner)
		{
			PlayerOwner->bShowMouseCursor = true;
			PlayerOwner->SetInputMode(FInputModeUIOnly());
		}
	}
}

void AMenuHUD::RemoveMenu()
{
	if (GEngine && GEngine->GameViewport && MenuWidgetContainer.IsValid())
	{
		GEngine->GameViewport->RemoveViewportWidgetContent(MenuWidgetContainer.ToSharedRef());
		if (PlayerOwner)
		{
			PlayerOwner->bShowMouseCursor = false;
			PlayerOwner->SetInputMode(FInputModeGameOnly());
		}
	}
}

void AMenuHUD::ShowDraggableMenu()
{
	if (GEngine && GEngine->GameViewport)
	{
		DraggableWidget = SNew(SDraggableWidget)
		//.Style(&WidgetStyle)
		.OwningHUD(this);
		GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(MenuWidgetContainer, SWeakWidget).PossiblyNullContent(DraggableWidget.ToSharedRef()));

		if (PlayerOwner)
		{
			PlayerOwner->bShowMouseCursor = true;
			PlayerOwner->SetInputMode(FInputModeUIOnly());
		}
	}
}

void AMenuHUD::RemoveDraggableMenu()
{
	if (GEngine && GEngine->GameViewport && MenuWidgetContainer.IsValid())
	{
		GEngine->GameViewport->RemoveViewportWidgetContent(MenuWidgetContainer.ToSharedRef());
		if (PlayerOwner)
		{
			PlayerOwner->bShowMouseCursor = false;
			PlayerOwner->SetInputMode(FInputModeGameOnly());
		}
	}
}

UMainGameInstance* AMenuHUD::GetMainGameInstance()
{
	return Cast<UMainGameInstance>(UGameplayStatics::GetGameInstance(this));
}
