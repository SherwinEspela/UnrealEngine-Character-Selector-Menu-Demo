// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/BaseButtonWidget.h"
#include "Widget/ButtonNavigationWidget.h"

void UButtonNavigationWidget::MoveUp()
{
	if (CurrentHighlightedButton == nullptr) return;
	NextButton = CurrentHighlightedButton->MoveUp();
	UpdateButtonState();
}

void UButtonNavigationWidget::MoveDown()
{
	if (CurrentHighlightedButton == nullptr) return;
	NextButton = CurrentHighlightedButton->MoveDown();
	UpdateButtonState();
}

void UButtonNavigationWidget::MoveLeft()
{
	if (CurrentHighlightedButton == nullptr) return;
	NextButton = CurrentHighlightedButton->MoveLeft();
	if (NextButton == nullptr && CurrentHighlightedButton->bCanToggleSet)
	{
		HandleToggleSet();
	}
	else {
		UpdateButtonState();
	}
}

void UButtonNavigationWidget::MoveRight()
{
	if (CurrentHighlightedButton == nullptr) return;
	NextButton = CurrentHighlightedButton->MoveRight();
	
	if (NextButton == nullptr && CurrentHighlightedButton->bCanToggleSet)
	{
		HandleToggleSet();
	}
	else {
		UpdateButtonState();
	}
}

void UButtonNavigationWidget::Select()
{
	if (CurrentSelectedButton == CurrentHighlightedButton) return;

	CurrentSelectedButton->SetUnselectedState();
	CurrentSelectedButton->bIsSelected = false;

	CurrentHighlightedButton->Select();
	//CurrentHighlightedButton->SelectButtonClicked();
	CurrentSelectedButton = CurrentHighlightedButton;
}

void UButtonNavigationWidget::SetHoverStateOnCurrentHighlightedButton()
{
	CurrentHighlightedButton->SetHoveredState();
}

void UButtonNavigationWidget::UpdateButtonState()
{
	if (NextButton)
	{
		if (!CurrentHighlightedButton->bIsSelected)
		{
			CurrentHighlightedButton->SetUnhoveredState();
		}
		NextButton->SetHoveredState();
		CurrentHighlightedButton = NextButton;
	}
}

void UButtonNavigationWidget::HandleToggleSet()
{
	if (!CurrentHighlightedButton->bIsSelected)
	{
		CurrentHighlightedButton->OnSetUnhoveredState();
	}
	
	OnToggleSet.Broadcast(this);
}
