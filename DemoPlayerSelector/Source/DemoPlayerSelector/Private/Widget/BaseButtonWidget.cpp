// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/BaseButtonWidget.h"
#include "Sound/SoundBase.h"
#include "Kismet/GameplayStatics.h"

UBaseButtonWidget* UBaseButtonWidget::MoveUp()
{
	return Up;
}

UBaseButtonWidget* UBaseButtonWidget::MoveDown()
{
	return Down;
}

UBaseButtonWidget* UBaseButtonWidget::MoveRight()
{
	return Right;
}

UBaseButtonWidget* UBaseButtonWidget::MoveLeft()
{
	return Left;
}

void UBaseButtonWidget::SetUnselectedState()
{
	OnSetUnselectedState();
}

void UBaseButtonWidget::SetHoveredState()
{
	if (SFXButton)
	{
		UGameplayStatics::PlaySound2D(this, SFXButton);
	}

	OnSetHoveredState();
}

void UBaseButtonWidget::SetUnhoveredState()
{
	OnSetUnhoveredState();
}

void UBaseButtonWidget::Select()
{
	if (!bIsSelected)
	{
		bIsSelected = true;
		OnSetSelectedState();
	}
}
