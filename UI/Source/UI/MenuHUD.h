// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MainGameInstance.h"
#include "GameFramework/HUD.h"
#include "MenuHUD.generated.h"

/**
 * 
 */
UCLASS()
class UI_API AMenuHUD : public AHUD
{
	GENERATED_BODY()

protected:
	TSharedPtr<class SMenuWidget> MenuWidget;
	TSharedPtr<class SDraggableWidget> DraggableWidget;
	TSharedPtr<class SWidget> MenuWidgetContainer;

	
	virtual void BeginPlay() override;

public:
	AMenuHUD();
	void ShowMenu();
	void RemoveMenu();
	void ShowDraggableMenu();
	void RemoveDraggableMenu();
	UMainGameInstance* GetMainGameInstance();
	
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameInstance")
	//TSubclassOf<UGameInstance> MainGameInstance;
	/** The button style used at runtime */
	//UPROPERTY(EditAnywhere, Category = "Appearance", meta = (DisplayName = "Style"))
	//FMenuSlateStyle WidgetStyle;
	
};
