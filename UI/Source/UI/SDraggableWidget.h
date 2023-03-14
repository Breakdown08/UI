// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class UI_API SDraggableWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SDraggableWidget) {}
	
	SLATE_ARGUMENT(TWeakObjectPtr<class AMenuHUD>, OwningHUD)
	
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
	TWeakObjectPtr<class AMenuHUD> OwningHUD;
};

