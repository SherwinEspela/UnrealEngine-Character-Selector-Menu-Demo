// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PreviewMovement.h"
#include "Widget/ButtonNavigationWidget.h"
#include "MainPlayerSelectorWidget.generated.h"

class UTextBlock;
class UAttributeWidget;
class UPreviewMovementButtonWidget;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPreviewMovementIdleSelected);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPreviewMovementWalkSelected);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPreviewMovementRunSelected);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPreviewMovementGesture1Selected);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPreviewMovementGesture2Selected);

/**
 * 
 */
UCLASS()
class DEMOPLAYERSELECTOR_API UMainPlayerSelectorWidget : public UButtonNavigationWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void SetSelectedPlayerName(FString SelectedPlayerName);

	UFUNCTION(BlueprintCallable)
	void SetDescription(FString NewDescription);

	UFUNCTION(BlueprintCallable)
	void SetAttributeValues(float Strength, float Intelligence, float Endurance, float Vigor, float Faith, float Dexterity, float Arcane);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayerChanged();

	void ResetPreviewButtons();

	UPROPERTY(BlueprintAssignable)
	FPreviewMovementIdleSelected OnPreviewMovementIdleSelected;

	UPROPERTY(BlueprintAssignable)
	FPreviewMovementWalkSelected OnPreviewMovementWalkSelected;

	UPROPERTY(BlueprintAssignable)
	FPreviewMovementRunSelected OnPreviewMovementRunSelected;

	UPROPERTY(BlueprintAssignable)
	FPreviewMovementGesture1Selected OnPreviewMovementGesture1Selected;

	UPROPERTY(BlueprintAssignable)
	FPreviewMovementGesture2Selected OnPreviewMovementGesture2Selected;

protected:
	void NativeConstruct() override;

private:
	UPROPERTY( meta = (BindWidget))
	TObjectPtr<UTextBlock> TextSelectedPlayerName;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> TextDescription;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UAttributeWidget> WAStrength;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UAttributeWidget> WAIntelligence;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UAttributeWidget> WAEndurance;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UAttributeWidget> WAVigor;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UAttributeWidget> WAFaith;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UAttributeWidget> WADexterity;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UAttributeWidget> WAArcane;

	UPROPERTY(meta = (BindWidget))
	UPreviewMovementButtonWidget* ButtonPreviewMovementIdle;

	UPROPERTY(meta = (BindWidget))
	UPreviewMovementButtonWidget* ButtonPreviewMovementWalk;

	UPROPERTY(meta = (BindWidget))
	UPreviewMovementButtonWidget* ButtonPreviewMovementRun;

	UPROPERTY(meta = (BindWidget))
	UPreviewMovementButtonWidget* ButtonPreviewMovementGesture1;

	UPROPERTY(meta = (BindWidget))
	UPreviewMovementButtonWidget* ButtonPreviewMovementGesture2;

	UFUNCTION()
	void HandlePreviewMovementIdleButtonClicked();

	UFUNCTION()
	void HandlePreviewMovementWalkButtonClicked();

	UFUNCTION()
	void HandlePreviewMovementRunButtonClicked();

	UFUNCTION()
	void HandlePreviewMovementGesture1ButtonClicked();

	UFUNCTION()
	void HandlePreviewMovementGesture2ButtonClicked();

	void SetNewMovement(UPreviewMovementButtonWidget* NewButton, EPreviewMovementType NewType);

	TObjectPtr<UPreviewMovementButtonWidget> CurrentPreviewMovementButton;
	EPreviewMovementType CurrentPreviewMovementType = EPreviewMovementType::PM_Idle;

	void SetupButtonMapping();
};
