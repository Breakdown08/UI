// Fill out your copyright notice in the Description page of Project Settings.


#include "SMenuWidget.h"

#include "MenuHUD.h"
#define LOCTEXT_NAMESPACE "MainMenu"
#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SMenuWidget::Construct(const FArguments& InArgs)
{
	bCanSupportFocus = true;
	OwningHUD = InArgs._OwningHUD;
	
	const FMargin ContentPadding = FMargin(500.f, 300.f);
	const FMargin ButtonPadding = FMargin(10.f);
	
	const FText TitleText = LOCTEXT("GameTitle", "Тестер материалов");
	const FText PlayText = LOCTEXT("PlayGame", "Играть");
	const FText QuitText = LOCTEXT("QuitGame", "Выход");

	//SetMenuStyle(InArgs._Style);
	
	FSlateFontInfo ButtonTextStyle = FCoreStyle::Get().GetFontStyle("EmbossedText");
	ButtonTextStyle.Size = 40.f;

	FSlateFontInfo TitleTextStyle = ButtonTextStyle;
	ButtonTextStyle.Size = 40.f;
	
	ChildSlot
	[
		SNew(SOverlay)
		+ SOverlay::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		[
			SNew(SImage)
			.ColorAndOpacity(FColor::Black)
		]
		+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		.Padding(ContentPadding)
		[
			SNew(SVerticalBox)

			//Title text
			+ SVerticalBox::Slot()
			[
				SNew(STextBlock)
				.Font(TitleTextStyle)
				.Text(TitleText)
				//.TextStyle(TextStyle)
				.Justification(ETextJustify::Center)
			]

			//Play Button
			+ SVerticalBox::Slot()
			.Padding(ButtonPadding)
			[
				SNew(SButton)
				.OnClicked(this, &SMenuWidget::OnPlayClicked)
				[
					SNew(STextBlock)
					.Font(ButtonTextStyle)
					.Text(PlayText)
					//.TextStyle(TextStyle)
					.Justification(ETextJustify::Center)
				]
			]
			

			//Quit Button
			+ SVerticalBox::Slot()
			.Padding(ButtonPadding)
			[
				SNew(SButton)
				.OnClicked(this, &SMenuWidget::OnQuitClicked)
				[
					SNew(STextBlock)
					.Font(ButtonTextStyle)
					.Text(QuitText)
					//.TextStyle(TextStyle)
					.Justification(ETextJustify::Center)
				]
			]
		]
	];
}

/*void SMenuWidget::SetMenuStyle(const FMenuSlateStyle* InStyle)
{
	TextStyle = &InStyle->TextStyle;
}*/

FReply SMenuWidget::OnPlayClicked() const
{
	if (OwningHUD.IsValid())
	{
		OwningHUD->RemoveMenu();
	}
	return FReply::Handled();
}

FReply SMenuWidget::OnQuitClicked() const
{
	UE_LOG(LogTemp, Warning, TEXT("НАЖАТА КНОПКА ВЫХОД"));

	if (OwningHUD.IsValid())
	{
		if (APlayerController* PC = OwningHUD->PlayerOwner)
		{
			PC->ConsoleCommand("quit");
		}
	}
	return FReply::Handled();
}
#undef LOCTEXT_NAMESPACE
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
