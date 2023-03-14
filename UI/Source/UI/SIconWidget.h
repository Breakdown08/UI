// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class UI_API SIconWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SIconWidget)
	{}
	SLATE_END_ARGS()
	
	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
	virtual FReply OnMouseButtonDown(const FGeometry& MyGeometry,
    const FPointerEvent& MouseEvent) override;
    virtual FReply OnDragDetected(const FGeometry& MyGeometry,
    const FPointerEvent& MouseEvent) override;
    virtual FReply OnMouseButtonUp(const FGeometry& MyGeometry,
    const FPointerEvent& MouseEvent) override;
    virtual FReply OnDrop(const FGeometry& MyGeometry,
    const FDragDropEvent& DragDropEvent) override;
    virtual FReply OnDragOver(const FGeometry& MyGeometry,
    const FDragDropEvent& DragDropEvent) override;
	
};
