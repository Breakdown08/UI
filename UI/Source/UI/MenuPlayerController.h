// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MenuPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class UI_API AMenuPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	AMenuPlayerController(const FObjectInitializer & Obj);
	FSimpleMulticastDelegate OnMouseButtonUp;
	void OpenMenu();
	void Test();
protected:
	virtual void SetupInputComponent() override;
	void OnLeftMouseButtonUp();
	void ShowMaterialsPanel();
private:
	bool IsMaterialsPanelOpened = false;
};
