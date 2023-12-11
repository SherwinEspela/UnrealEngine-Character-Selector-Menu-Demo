// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AttributeWidget.generated.h"

class UTextBlock;
class UProgressBar;

/**
 * 
 */
UCLASS()
class DEMOPLAYERSELECTOR_API UAttributeWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void SetAttributeValue(float NewValue);

	UFUNCTION(BlueprintImplementableEvent)
	void OnAttributeValueChanged(float NewValue);

private:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UProgressBar> ProgressBarAttribute;
};
