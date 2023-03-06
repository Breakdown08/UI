// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GamePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class UI_API AGamePlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	AGamePlayerController(const FObjectInitializer & Obj);
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
