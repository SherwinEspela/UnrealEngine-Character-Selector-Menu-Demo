// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/ButtonsWidget.h"
#include "Widget/SelectButtonWidget.h"
#include "UI/HUD/PlayerSelectorHUD.h"

void UButtonsWidget::NativeConstruct()
{
	Super::NativeConstruct();

	SelectButton1->OnSelectButtonClicked.AddDynamic(this, &UButtonsWidget::HandlePlayerSelected);
	SelectButton2->OnSelectButtonClicked.AddDynamic(this, &UButtonsWidget::HandlePlayerSelected);
	SelectButton3->OnSelectButtonClicked.AddDynamic(this, &UButtonsWidget::HandlePlayerSelected);
	SelectButton4->OnSelectButtonClicked.AddDynamic(this, &UButtonsWidget::HandlePlayerSelected);
	SelectButton5->OnSelectButtonClicked.AddDynamic(this, &UButtonsWidget::HandlePlayerSelected);
	SelectButton6->OnSelectButtonClicked.AddDynamic(this, &UButtonsWidget::HandlePlayerSelected);

	SelectButtons.Add(SelectButton1);
	SelectButtons.Add(SelectButton2);
	SelectButtons.Add(SelectButton3);
	SelectButtons.Add(SelectButton4);
	SelectButtons.Add(SelectButton5);
	SelectButtons.Add(SelectButton6);

	SetupButtonMapping();
}

void UButtonsWidget::HandlePlayerSelected(FName SelectedRowName, USelectButtonWidget* NewCurrentSelectButton)
{
	if (CurrentSelectedButton == NewCurrentSelectButton) return;
	if (CurrentSelectedButton) CurrentSelectedButton->SetUnselectedState();
	CurrentSelectedButton = NewCurrentSelectButton;
	OnRowNameSelected.Broadcast(SelectedRowName);
}

void UButtonsWidget::SetNextButton(FString Name, UTexture2D* Photo)
{
	auto sb = SelectButtons[NextButtonIndex];
	if (sb)
	{
		sb->SetPlayerName(Name);
		sb->SetCharacterPhoto(Photo);
		NextButtonIndex++;
		NextButtonIndex = FMath::Clamp(NextButtonIndex, 0, 5);
	}
}

void UButtonsWidget::SetNextButtonStates(FName RowName, FString CharacterName, UTexture2D* CharacterPhoto)
{
	USelectButtonWidget* sb = SelectButtons[NextButtonIndex];
	if (sb)
	{
		sb->SetStates(RowName, CharacterName, CharacterPhoto);
		NextButtonIndex++;
		NextButtonIndex = FMath::Clamp(NextButtonIndex, 0, 5);
	}
}

void UButtonsWidget::SetButtonStates(TArray<FPlayerRow*> PlayerRows)
{
	for (uint8 i = 1; i < sizeof(PlayerRows) ; i++)
	{
		FPlayerRow* Row = PlayerRows[i];
	}	
}

void UButtonsWidget::SetupButtonMapping()
{
	SelectButton1->Right = SelectButton2;
	SelectButton1->Down = SelectButton3;

	SelectButton2->Left = SelectButton1;
	SelectButton2->Down = SelectButton4;

	SelectButton3->Right = SelectButton4;
	SelectButton3->Up = SelectButton1;
	SelectButton3->Down = SelectButton5;

	SelectButton4->Left = SelectButton3;
	SelectButton4->Up = SelectButton2;
	SelectButton4->Down = SelectButton6;

	SelectButton5->Right = SelectButton6;
	SelectButton5->Up = SelectButton3;

	SelectButton6->Left = SelectButton5;
	SelectButton6->Up = SelectButton4;

	CurrentHighlightedButton = SelectButton1;
	CurrentSelectedButton = SelectButton1;
	CurrentSelectedButton->Select();

	SelectButton2->bCanToggleSet = true;
	SelectButton4->bCanToggleSet = true;
	SelectButton6->bCanToggleSet = true;
}
