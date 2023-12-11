// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BaseButtonWidget.generated.h"

/**
 * 
 */
UCLASS()
class DEMOPLAYERSELECTOR_API UBaseButtonWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual UBaseButtonWidget* MoveUp();
	virtual UBaseButtonWidget* MoveDown();
	virtual UBaseButtonWidget* MoveLeft();
	virtual UBaseButtonWidget* MoveRight();

	UBaseButtonWidget* Up;
	UBaseButtonWidget* Down;
	UBaseButtonWidget* Left;
	UBaseButtonWidget* Right;

	UPROPERTY(BlueprintReadOnly)
	bool bIsSelected = false;

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetUnselectedState();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetHoveredState();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetUnhoveredState();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetSelectedState();

	virtual void SetUnselectedState();
	virtual void SetHoveredState();
	virtual void SetUnhoveredState();
	virtual void Select();

	bool bCanToggleSet = false;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USoundBase* SFXButton;
};
