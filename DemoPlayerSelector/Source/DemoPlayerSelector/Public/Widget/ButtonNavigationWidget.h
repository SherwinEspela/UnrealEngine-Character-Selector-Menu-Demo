// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ButtonNavigationWidget.generated.h"

class UBaseButtonWidget;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnToggleSetSignature, class UButtonNavigationWidget*, NavigationWidget);

/**
 * 
 */
UCLASS()
class DEMOPLAYERSELECTOR_API UButtonNavigationWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
	void Select();
	void SetHoverStateOnCurrentHighlightedButton();

	FOnToggleSetSignature OnToggleSet;

protected:
	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UBaseButtonWidget* CurrentSelectedButton;

	UBaseButtonWidget* NextButton;
	UBaseButtonWidget* CurrentHighlightedButton;

private:
	void UpdateButtonState();
	void HandleToggleSet();

};
