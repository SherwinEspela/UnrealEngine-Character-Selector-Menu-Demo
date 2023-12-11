// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/PlayerSelectorHUD.h"
#include "Blueprint/UserWidget.h"
#include "Widget/MainPlayerSelectorWidget.h"
#include "Widget/ButtonsWidget.h"
#include "DCSCharacter.h"
#include "PreviewMovement.h"

void APlayerSelectorHUD::BeginPlay()
{
	Super::BeginPlay();

	UWorld* World = GetWorld();

	MainWidget = CreateWidget<UMainPlayerSelectorWidget>(World, MainWidgetClass);
	MainWidget->AddToViewport();

	ButtonsWidget = CreateWidget<UButtonsWidget>(World, ButtonsWidgetClass);
	ButtonsWidget->AddToViewport();
	ButtonsWidget->OnToggleSet.AddDynamic(this, &APlayerSelectorHUD::HandleToggleToOtherSetFromButtonsWidget);
	ButtonsWidget->OnRowNameSelected.AddDynamic(this, &APlayerSelectorHUD::SetNewAvatar);
	
	if (PlayerRowDataTable)
	{
		TArray<FName> RowNames = PlayerRowDataTable->GetRowNames();
		for(FName RowName : RowNames)
		{
			FPlayerRow* Row = PlayerRowDataTable->FindRow<FPlayerRow>(RowName, "");
			ButtonsWidget->SetNextButtonStates(RowName, Row->Name, Row->Photo);
		}
	}

	MainWidget->OnPreviewMovementIdleSelected.AddDynamic(this, &APlayerSelectorHUD::HandleSelectedPreviewMovementIdle);
	MainWidget->OnPreviewMovementWalkSelected.AddDynamic(this, &APlayerSelectorHUD::HandleSelectedPreviewMovementWalk);
	MainWidget->OnPreviewMovementRunSelected.AddDynamic(this, &APlayerSelectorHUD::HandleSelectedPreviewMovementRun);
	MainWidget->OnPreviewMovementGesture1Selected.AddDynamic(this, &APlayerSelectorHUD::HandleSelectedPreviewMovementGesture1);
	MainWidget->OnPreviewMovementGesture2Selected.AddDynamic(this, &APlayerSelectorHUD::HandleSelectedPreviewMovementGesture2);
	MainWidget->OnToggleSet.AddDynamic(this, &APlayerSelectorHUD::HandleToggleToOtherSetFromButtonsWidget);

	CurrentNavigationWidget = ButtonsWidget;

	// Initialize Avatar
	SetAvatar(CurrentRowName);
}

void APlayerSelectorHUD::SetAvatar(FName SelectedRowName)
{
	FPlayerRow* Row = PlayerRowDataTable->FindRow<FPlayerRow>(SelectedRowName, "");

	SetSelectedCharacterName(Row->Name);
	MainWidget->SetDescription(Row->Description);
	MainWidget->SetAttributeValues(
		Row->AttributeStrength,
		Row->AttributeIntelligence,
		Row->AttributeEndurance,
		Row->AttributeVigor,
		Row->AttributeFaith,
		Row->AttributeDexterity,
		Row->AttributeArcane
	);

	CurrentAvatar = GetWorld()->SpawnActor<ADCSCharacter>(Row->Avatar, FVector(0, 0, 128.f), FRotator(0, 145.f, 0));
	CurrentAvatar->SetPreviewMovementType(EPreviewMovementType::PM_Spawn);
	CurrentAvatar->PlayAudio(EPreviewMovementType::PM_Spawn);
	CurrentRowName = SelectedRowName;
}

void APlayerSelectorHUD::SetNewAvatar(FName SelectedRowName)
{
	if (SelectedRowName == CurrentRowName) return;
	if (CurrentAvatar) {
		CurrentAvatar->StopAudio();
		CurrentAvatar->Destroy();
	}
	SetAvatar(SelectedRowName);
	MainWidget->ResetPreviewButtons();
}

void APlayerSelectorHUD::HandleSelectedPreviewMovementIdle()
{
	PlayPreviewMovement(EPreviewMovementType::PM_Idle);
}

void APlayerSelectorHUD::HandleSelectedPreviewMovementWalk()
{
	PlayPreviewMovement(EPreviewMovementType::PM_Walk);
}

void APlayerSelectorHUD::HandleSelectedPreviewMovementRun()
{
	PlayPreviewMovement(EPreviewMovementType::PM_Run);
}

void APlayerSelectorHUD::HandleSelectedPreviewMovementGesture1()
{
	PlayPreviewMovement(EPreviewMovementType::PM_Gesture1);
}

void APlayerSelectorHUD::HandleSelectedPreviewMovementGesture2()
{
	PlayPreviewMovement(EPreviewMovementType::PM_Gesture2);
}

void APlayerSelectorHUD::SetSelectedCharacterName(FString SelectedPlayerName)
{
	MainWidget->SetSelectedPlayerName(SelectedPlayerName);
}

void APlayerSelectorHUD::PlayPreviewMovement(EPreviewMovementType MovementType)
{
	if (CurrentAvatar) {
		CurrentAvatar->SetPreviewMovementType(MovementType);
		CurrentAvatar->PlayAudio(MovementType);
	}
}

void APlayerSelectorHUD::HandleToggleToOtherSetFromButtonsWidget(UButtonNavigationWidget* NewNavigationWidget)
{
	bIsLeftButtonSet = !bIsLeftButtonSet;
	if (bIsLeftButtonSet)
	{
		CurrentNavigationWidget = ButtonsWidget;
	}
	else {
		CurrentNavigationWidget = MainWidget;
	}
	
	CurrentNavigationWidget->SetHoverStateOnCurrentHighlightedButton();
}
