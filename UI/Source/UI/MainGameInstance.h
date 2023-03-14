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
	virtual void Init() override;
	virtual void OnStart() override;
};
