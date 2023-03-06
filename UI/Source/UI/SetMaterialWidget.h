// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SetMaterialWidget.generated.h"

/**
 * 
 */
UCLASS()
class UI_API USetMaterialWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry,
	const FPointerEvent& InMouseEvent) override;
protected:
	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> DraggedActorClass;
	UPROPERTY()
	AActor * DraggedActor;
	UMaterial * DraggedMaterial;
	UPROPERTY()
	APlayerController* PlayerController;
	void OnMouseButtonUp();
	void SetMaterial();
};
