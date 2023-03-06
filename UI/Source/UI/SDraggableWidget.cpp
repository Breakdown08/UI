// Fill out your copyright notice in the Description page of Project Settings.


#include "SDraggableWidget.h"
#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SDraggableWidget::Construct(const FArguments& InArgs)
{
	/*
	ChildSlot
	[
		// Populate the widget
	];
	*/
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

// используем DetectDrag для инициализации ДрадДропа
FReply SDraggableWidget::OnMouseButtonDown(const FGeometry& MyGeometry,
const FPointerEvent& MouseEvent)
{
	if (MouseEvent.GetEffectingButton() == EKeys::LeftMouseButton)
	{
		return FReply::Handled()
		.DetectDrag(SharedThis(this), EKeys::LeftMouseButton)
		.CaptureMouse(SharedThis(this));
	}
	return FReply::Unhandled();
}
FReply SDraggableWidget::OnDragDetected(const FGeometry& MyGeometry,
const FPointerEvent& MouseEvent)
{
	// логика OnDragDetected
	return FReply::Unhandled();
}
// ReleaseMouseCapture, чтоб перестать захватывать мышь этим виджетом после
// CaptureMouse в OnMouseButtonDown
FReply SDraggableWidget::OnMouseButtonUp(const FGeometry& MyGeometry,
const FPointerEvent& MouseEvent)
{
	if (MouseEvent.GetEffectingButton() == EKeys::LeftMouseButton)
	{
		return FReply::Handled().ReleaseMouseCapture();
	}
	return FReply::Unhandled();
}
FReply SDraggableWidget::OnDrop(const FGeometry& MyGeometry,
const FDragDropEvent& DragDropEvent)
{
	// логика OnDrop
	return FReply::Unhandled();
}