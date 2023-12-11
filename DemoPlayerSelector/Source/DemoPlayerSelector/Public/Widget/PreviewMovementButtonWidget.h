// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Widget/BaseButtonWidget.h"
#include "PreviewMovementButtonWidget.generated.h"

class UButton;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPreviewMovementButtonClicked);

/**
 * 
 */
UCLASS()
class DEMOPLAYERSELECTOR_API UPreviewMovementButtonWidget : public UBaseButtonWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintAssignable)
	FPreviewMovementButtonClicked OnPreviewMovmentButtonClicked;

	//void SetUnselectedState() override;
	//void SetHoveredState() override;
	//void SetUnhoveredState() override;
	void Select() override;

protected:
	void NativeConstruct() override;

private:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UButton> Button;

	UFUNCTION()
	void HandleButtonClicked();
};
