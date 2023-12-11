// Fill out your copyright notice in the Description page of Project Settings.

#include "Widget/SelectButtonWidget.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"

void USelectButtonWidget::NativeConstruct()
{
	Super::NativeConstruct();
	ButtonSelect->OnClicked.AddDynamic(this, &USelectButtonWidget::SelectButtonClicked);
}

void USelectButtonWidget::SelectButtonClicked()
{
	OnSelectButtonClicked.Broadcast(RowName, this);
}

void USelectButtonWidget::SetPlayerName(FString Name)
{
	TextCharacterName->SetText(FText::FromString(Name));
}

void USelectButtonWidget::SetCharacterPhoto(UTexture2D* TexturePhoto)
{
	ImageCharacterPhoto->SetBrushFromTexture(TexturePhoto, true);
}

void USelectButtonWidget::SetStates(FName NewRowName, FString CharacterName, UTexture2D* CharacterPhoto)
{
	RowName = NewRowName;
	TextCharacterName->SetText(FText::FromString(CharacterName));
	ImageCharacterPhoto->SetBrushFromTexture(CharacterPhoto, true);
}

//void USelectButtonWidget::SetUnselectedState()
//{
//	Super::SetUnselectedState();
//}
//
//void USelectButtonWidget::SetHoveredState()
//{
//	Super::SetHoveredState();
//}
//
//void USelectButtonWidget::SetUnhoveredState()
//{
//	Super::SetUnhoveredState();
//}

void USelectButtonWidget::Select()
{
	Super::Select();
	SelectButtonClicked();
}
