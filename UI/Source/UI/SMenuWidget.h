// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Widgets/SCompoundWidget.h"
#include "CoreMinimal.h"
#include "SlateBasics.h"
#include "SlateExtras.h"


/**
 * 
 */
class UI_API SMenuWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMenuWidget) {}

	SLATE_ARGUMENT(TWeakObjectPtr<class AMenuHUD>, OwningHUD)

	//SLATE_STYLE_ARGUMENT(FMenuSlateStyle, Style)

	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);
	//void SetMenuStyle(const FMenuSlateStyle* InStyle);
	
	FReply OnPlayClicked() const;
	FReply OnQuitClicked() const;
	
	TWeakObjectPtr<class AMenuHUD> OwningHUD;

	virtual bool SupportsKeyboardFocus() const override {return true;};

protected:
	/** Style resource for text */
	const FTextBlockStyle* TextStyle = nullptr;
};
