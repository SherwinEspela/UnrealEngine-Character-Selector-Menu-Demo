// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Widget/ButtonNavigationWidget.h"
#include "ButtonsWidget.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPlayerSelectedEvent, FName, SelectedRowName);

class USelectButtonWidget;
struct FPlayerRow;

/**
 * 
 */
UCLASS()
class DEMOPLAYERSELECTOR_API UButtonsWidget : public UButtonNavigationWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintAssignable)
	FPlayerSelectedEvent OnRowNameSelected;

	UFUNCTION(BlueprintCallable)
	void SetNextButton(FString Name, UTexture2D* Photo);

	UFUNCTION(BlueprintCallable)
	void SetNextButtonStates(FName RowName, FString CharacterName, UTexture2D* CharacterPhoto);

	void SetButtonStates(TArray<FPlayerRow*> PlayerRows);

protected:
	void NativeConstruct() override;
	
private:

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), meta =(AllowPrivateAccess = "true"))
	USelectButtonWidget* SelectButton1;

	UPROPERTY(meta = (BindWidget))
	USelectButtonWidget* SelectButton2;

	UPROPERTY(meta = (BindWidget))
	USelectButtonWidget* SelectButton3;

	UPROPERTY(meta = (BindWidget))
	USelectButtonWidget* SelectButton4;

	UPROPERTY(meta = (BindWidget))
	USelectButtonWidget* SelectButton5;

	UPROPERTY(meta = (BindWidget))
	USelectButtonWidget* SelectButton6;

	UPROPERTY(EditAnywhere)
	FString PlayerName1;

	UPROPERTY(EditAnywhere)
	FString PlayerName2;

	UPROPERTY(EditAnywhere)
	FString PlayerName3;

	UPROPERTY(EditAnywhere)
	FString PlayerName4;

	UPROPERTY(EditAnywhere)
	FString PlayerName5;

	UPROPERTY(EditAnywhere)
	FString PlayerName6;
	
	UFUNCTION()
	void HandlePlayerSelected(FName SelectedRowName, USelectButtonWidget* NewCurrentSelectButton);

	int NextButtonIndex = 0;
	TArray<USelectButtonWidget*> SelectButtons;

	void SetupButtonMapping();
};
