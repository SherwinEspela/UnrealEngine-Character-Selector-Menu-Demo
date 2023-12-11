// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Engine/DataTable.h"
#include "DCSCharacter.h"
#include "PlayerSelectorHUD.generated.h"

class UMainPlayerSelectorWidget;
class UButtonsWidget;
class UDataTable;
class UInputMappingContext;
class UInputAction;
class ADCSCharacter;
class UButtonNavigationWidget;

USTRUCT(BlueprintType)
struct FPlayerRow : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString Name = "";

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString Description = "";

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UTexture2D* Photo = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<ADCSCharacter> Avatar = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float AttributeStrength = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float AttributeIntelligence = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float AttributeEndurance = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float AttributeVigor = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float AttributeFaith = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float AttributeDexterity = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float AttributeArcane = 0.5f;
};


/**
 * 
 */
UCLASS()
class DEMOPLAYERSELECTOR_API APlayerSelectorHUD : public AHUD
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UMainPlayerSelectorWidget> PlayerSelectorWidget;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UButtonsWidget> ButtonsWidgetClass;

	UPROPERTY(BlueprintReadOnly)
	UButtonsWidget* ButtonsWidget;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UDataTable* PlayerRowDataTable;

	UFUNCTION(BlueprintCallable)
	void SetSelectedCharacterName(FString SelectedPlayerName);

	// UFUNCTION(BlueprintImplementableEvent) reference samples
	/*UFUNCTION(BlueprintImplementableEvent)
	void ButtonsWidgetCreated();

	UFUNCTION(BlueprintImplementableEvent)
	void RowNameSelected(FName RowName);*/

public:
	//FORCEINLINE UButtonsWidget* GetButtonsWidget() const { return ButtonsWidget; }
	FORCEINLINE UButtonNavigationWidget* GetCurrentNavigationWidget() const { return CurrentNavigationWidget; }

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void HandleToggleToOtherSetFromButtonsWidget(UButtonNavigationWidget* NewNavigationWidget);

private:
	ADCSCharacter* CurrentAvatar;
	FName CurrentRowName = "1";
	bool bIsInitialized = false;

	void SetAvatar(FName SelectedRowName);

	UPROPERTY(EditAnywhere)
	TSubclassOf<UMainPlayerSelectorWidget> MainWidgetClass;

	UPROPERTY()
	UMainPlayerSelectorWidget* MainWidget;

	UFUNCTION()
	void SetNewAvatar(FName SelectedRowName);

	UFUNCTION()
	void HandleSelectedPreviewMovementIdle();

	UFUNCTION()
	void HandleSelectedPreviewMovementWalk();

	UFUNCTION()
	void HandleSelectedPreviewMovementRun();

	UFUNCTION()
	void HandleSelectedPreviewMovementGesture1();

	UFUNCTION()
	void HandleSelectedPreviewMovementGesture2();

	void PlayPreviewMovement(EPreviewMovementType MovementType);

	UButtonNavigationWidget* CurrentNavigationWidget;

	bool bIsLeftButtonSet = true;
};
