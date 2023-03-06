// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "GameFramework/GameMode.h"
#include "MainGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class UI_API UMainGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	UMainGameInstance(const FObjectInitializer& ObjectInitializer);
	void SetPlayerController(TSubclassOf<APlayerController> PlayerController);
	virtual void Init() override;
	//void ShowWidget(EWidgetType WidgetType);
	//TSubclassOf<class UUserWidget> GetWidgetByType(EWidgetType WidgetType);
	virtual void OnStart() override;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	//TSubclassOf<AGameMode> MenuGameMode;
	//TSubclassOf<APlayerController> GamePlayerController;
	//TSubclassOf<APlayerController> MenuPlayerController;
	TWeakObjectPtr<class AMenuGameMode> MenuGameMode;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	TSubclassOf<APlayerController> GamePlayerController;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	TSubclassOf<APlayerController> MenuPlayerController;

private:
	//TSubclassOf<class UUserWidget> GameOverWidgetClass;
	//TSubclassOf<class UUserWidget> MainMenuWidgetClass;
};
