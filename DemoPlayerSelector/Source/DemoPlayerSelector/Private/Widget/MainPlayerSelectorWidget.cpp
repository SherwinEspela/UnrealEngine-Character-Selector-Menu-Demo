// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/MainPlayerSelectorWidget.h"
#include "Components/TextBlock.h"
#include "Widget/AttributeWidget.h"
#include "Widget/PreviewMovementButtonWidget.h"
#include "Widget/PreviewMovementButtonWidget.h"

void UMainPlayerSelectorWidget::NativeConstruct()
{
	Super::NativeConstruct();

	ButtonPreviewMovementIdle->OnPreviewMovmentButtonClicked.AddDynamic(this, &UMainPlayerSelectorWidget::HandlePreviewMovementIdleButtonClicked);
	ButtonPreviewMovementWalk->OnPreviewMovmentButtonClicked.AddDynamic(this, &UMainPlayerSelectorWidget::HandlePreviewMovementWalkButtonClicked);
	ButtonPreviewMovementRun->OnPreviewMovmentButtonClicked.AddDynamic(this, &UMainPlayerSelectorWidget::HandlePreviewMovementRunButtonClicked);
	ButtonPreviewMovementGesture1->OnPreviewMovmentButtonClicked.AddDynamic(this, &UMainPlayerSelectorWidget::HandlePreviewMovementGesture1ButtonClicked);
	ButtonPreviewMovementGesture2->OnPreviewMovmentButtonClicked.AddDynamic(this, &UMainPlayerSelectorWidget::HandlePreviewMovementGesture2ButtonClicked);

	SetupButtonMapping();
}

void UMainPlayerSelectorWidget::HandlePreviewMovementIdleButtonClicked()
{
	SetNewMovement(ButtonPreviewMovementIdle, EPreviewMovementType::PM_Idle);
}

void UMainPlayerSelectorWidget::HandlePreviewMovementWalkButtonClicked()
{
	SetNewMovement(ButtonPreviewMovementWalk, EPreviewMovementType::PM_Walk);
}

void UMainPlayerSelectorWidget::HandlePreviewMovementRunButtonClicked()
{
	SetNewMovement(ButtonPreviewMovementRun, EPreviewMovementType::PM_Run);
}

void UMainPlayerSelectorWidget::HandlePreviewMovementGesture1ButtonClicked()
{
	SetNewMovement(ButtonPreviewMovementGesture1, EPreviewMovementType::PM_Gesture1);
}

void UMainPlayerSelectorWidget::HandlePreviewMovementGesture2ButtonClicked()
{
	SetNewMovement(ButtonPreviewMovementGesture2, EPreviewMovementType::PM_Gesture2);
}

void UMainPlayerSelectorWidget::SetNewMovement(UPreviewMovementButtonWidget* NewButton, EPreviewMovementType NewPreviewMovementType)
{
	if (CurrentPreviewMovementType == NewPreviewMovementType) return;
	if (CurrentPreviewMovementButton) {
		CurrentPreviewMovementButton->SetUnselectedState();
		CurrentPreviewMovementButton->bIsSelected = false;
	}
	NewButton->bIsSelected = true;
	CurrentPreviewMovementButton = NewButton;
	CurrentPreviewMovementType = NewPreviewMovementType;

	switch (NewPreviewMovementType)
	{
		case EPreviewMovementType::PM_Idle:
			OnPreviewMovementIdleSelected.Broadcast();
			break;

		case EPreviewMovementType::PM_Walk:
			OnPreviewMovementWalkSelected.Broadcast();
			break;

		case EPreviewMovementType::PM_Run:
			OnPreviewMovementRunSelected.Broadcast();
			break;

		case EPreviewMovementType::PM_Gesture1:
			OnPreviewMovementGesture1Selected.Broadcast();
			break;

		case EPreviewMovementType::PM_Gesture2:
			OnPreviewMovementGesture2Selected.Broadcast();
			break;

		default:
			break;
	}
	
}

void UMainPlayerSelectorWidget::SetSelectedPlayerName(FString SelectedPlayerName)
{
	OnPlayerChanged();
	TextSelectedPlayerName->SetText(FText::FromString(SelectedPlayerName));
}

void UMainPlayerSelectorWidget::SetDescription(FString NewDescription)
{
	TextDescription->SetText(FText::FromString(NewDescription));
}

void UMainPlayerSelectorWidget::SetAttributeValues(float Strength, float Intelligence, float Endurance, float Vigor, float Faith, float Dexterity, float Arcane)
{
	if (WAStrength) WAStrength->SetAttributeValue(Strength);
	if (WAIntelligence) WAIntelligence->SetAttributeValue(Intelligence);
	if (WAEndurance) WAEndurance->SetAttributeValue(Endurance);
	if (WAVigor) WAVigor->SetAttributeValue(Vigor);
	if (WAFaith) WAFaith->SetAttributeValue(Faith);
	if (WADexterity) WADexterity->SetAttributeValue(Dexterity);
	if (WAArcane) WAArcane->SetAttributeValue(Arcane);
}

void UMainPlayerSelectorWidget::ResetPreviewButtons()
{
	if (CurrentPreviewMovementButton && CurrentPreviewMovementButton->bIsSelected) {
		CurrentPreviewMovementButton->SetUnselectedState();
		CurrentPreviewMovementButton->bIsSelected = false;
		CurrentPreviewMovementButton = nullptr;
	}
}

void UMainPlayerSelectorWidget::SetupButtonMapping()
{
	ButtonPreviewMovementIdle->Right = ButtonPreviewMovementWalk;
	ButtonPreviewMovementIdle->Down = ButtonPreviewMovementGesture1;

	ButtonPreviewMovementWalk->Left = ButtonPreviewMovementIdle;
	ButtonPreviewMovementWalk->Right = ButtonPreviewMovementRun;
	ButtonPreviewMovementWalk->Down = ButtonPreviewMovementGesture1;

	ButtonPreviewMovementRun->Left = ButtonPreviewMovementWalk;
	ButtonPreviewMovementRun->Down = ButtonPreviewMovementGesture2;

	ButtonPreviewMovementGesture1->Right = ButtonPreviewMovementGesture2;
	ButtonPreviewMovementGesture1->Up = ButtonPreviewMovementIdle;
	
	ButtonPreviewMovementGesture2->Left = ButtonPreviewMovementGesture1;
	ButtonPreviewMovementGesture2->Up = ButtonPreviewMovementRun;

	ButtonPreviewMovementIdle->bCanToggleSet = true;
	ButtonPreviewMovementGesture1->bCanToggleSet = true;

	CurrentHighlightedButton = ButtonPreviewMovementIdle;
	CurrentSelectedButton = ButtonPreviewMovementIdle;
	CurrentSelectedButton->Select();
}
