// Fill out your copyright notice in the Description page of Project Settings.

#include "SIconWidget.h"
#include "ImageUtils.h"
#include "SlateOptMacros.h"
#include "Widgets/Images/SImage.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION



void SIconWidget::Construct(const FArguments& InArgs)
{
	FString TexturePath = FPaths::ProjectContentDir() / TEXT("Core/Materials/Wood/wood.jpg");
	UTexture2D* Texture = FImageUtils::ImportFileAsTexture2D(TexturePath);
	ChildSlot
	[
		SNew(SOverlay)
		+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		[
			SNew(SImage)
			.Image(new FSlateDynamicImageBrush(Texture, FVector2D(128, 128), FName(*TexturePath)))
		]
	];
	
}

// используем DetectDrag для инициализации ДрадДропа
FReply SIconWidget::OnMouseButtonDown(const FGeometry& MyGeometry,
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
FReply SIconWidget::OnDragDetected(const FGeometry& MyGeometry,
const FPointerEvent& MouseEvent)
{
	FReply Reply = FReply::Handled().CaptureMouse(SharedThis(this));
	if (Reply.GetMouseCaptor().IsValid())
	{
		GEngine->AddOnScreenDebugMessage(-1,200,FColor::Green, SharedThis(this).Get().ToString());
	}
	return FReply::Unhandled();
}
// ReleaseMouseCapture, чтоб перестать захватывать мышь этим виджетом после
// CaptureMouse в OnMouseButtonDown
FReply SIconWidget::OnMouseButtonUp(const FGeometry& MyGeometry,
const FPointerEvent& MouseEvent)
{
	if (MouseEvent.GetEffectingButton() == EKeys::LeftMouseButton)
	{
		return FReply::Handled().ReleaseMouseCapture();
	}
	return FReply::Unhandled();
}
FReply SIconWidget::OnDrop(const FGeometry& MyGeometry,
const FDragDropEvent& DragDropEvent)
{
	// логика OnDrop
	return FReply::Unhandled();
}

FReply SIconWidget::OnDragOver(const FGeometry& MyGeometry, const FDragDropEvent& DragDropEvent)
{
	GEngine->AddOnScreenDebugMessage(-1,200,FColor::Green,DragDropEvent.ToText().ToString());
	return SCompoundWidget::OnDragOver(MyGeometry, DragDropEvent);
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
