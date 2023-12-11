// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "DCSPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
class APlayerSelectorHUD;

/**
 * 
 */
UCLASS()
class DEMOPLAYERSELECTOR_API ADCSPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

	UPROPERTY(EditDefaultsOnly, Category = "Player Input")
	TObjectPtr<UInputMappingContext> InputMappingContextPlayer;

	UPROPERTY(EditDefaultsOnly, Category = "Player Input")
	TObjectPtr<UInputAction> InputActionDPadLeft;

	UPROPERTY(EditDefaultsOnly, Category = "Player Input")
	TObjectPtr<UInputAction> InputActionDPadRight;

	UPROPERTY(EditDefaultsOnly, Category = "Player Input")
	TObjectPtr<UInputAction> InputActionDPadUp;

	UPROPERTY(EditDefaultsOnly, Category = "Player Input")
	TObjectPtr<UInputAction> InputActionDPadDown;

	UPROPERTY(EditDefaultsOnly, Category = "Player Input")
	TObjectPtr<UInputAction> InputActionButtonA;

	UPROPERTY(EditDefaultsOnly, Category = "Player Input")
	TObjectPtr<UInputAction> InputActionReloadLevel;

private:
	APlayerSelectorHUD* PlayerSelectorHUD;

	void DPadLeftTapped();
	void DPadRightTapped();
	void DPadUpTapped();
	void DPadDownTapped();
	void ButtonATapped();
	void ReloadLevel();
};
