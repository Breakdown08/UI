// Fill out your copyright notice in the Description page of Project Settings.


#include "SDraggableWidget.h"
#include "SlateOptMacros.h"
#define LOCTEXT_NAMESPACE "DragNDrop"
#include "SIconWidget.h"
#include "Blueprint/DragDropOperation.h"
#include "Slate/UMGDragDropOp.h"
#include "Widgets/Images/SImage.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SDraggableWidget::Construct(const FArguments& InArgs)
{
	const FMargin ContentPadding = FMargin(500.f, 300.f);
	const FMargin ButtonPadding = FMargin(10.f);
	
	const FText TitleText = LOCTEXT("Title", "Панель материалов");

	FSlateFontInfo ButtonTextStyle = FCoreStyle::Get().GetFontStyle("EmbossedText");
	ButtonTextStyle.Size = 40.f;

	FSlateFontInfo TitleTextStyle = ButtonTextStyle;
	ButtonTextStyle.Size = 40.f;

	//Конструктор контейнера панели материалов
	TSharedPtr<SHorizontalBox> Container = SNew(SHorizontalBox);
	for (int32 idx = 0; idx < 2; idx++)
	{
		Container->AddSlot()
		.Padding(ButtonPadding)
		.VAlign(VAlign_Bottom)
		.HAlign(HAlign_Right)
		[
			SNew(SIconWidget)
		];
	}
	
	
	ChildSlot
	[
		SNew(SOverlay)
		+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		.Padding(ContentPadding)
		[
			Container.ToSharedRef()
		]
	];
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION




#undef LOCTEXT_NAMESPACE
