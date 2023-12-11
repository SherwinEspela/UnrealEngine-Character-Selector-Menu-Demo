// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Widget/BaseButtonWidget.h"
#include "SelectButtonWidget.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSelectButtonClickedSignature, FName, SelectedRowName, USelectButtonWidget*, SelectButton);

class UTextBlock;
class UButton;
class UImage;
class UTexture2D;
class USoundBase;

/**
 * 
 */
UCLASS()
class DEMOPLAYERSELECTOR_API USelectButtonWidget : public UBaseButtonWidget
{
	GENERATED_BODY()
public:
	void SetPlayerName(FString Name);
	void SetCharacterPhoto(UTexture2D* TexturePhoto);
	void SetStates(FName NewRowName, FString CharacterName, UTexture2D* CharacterPhoto);

	UPROPERTY(BlueprintAssignable)
	FOnSelectButtonClickedSignature OnSelectButtonClicked;

	UPROPERTY(EditDefaultsOnly, Category = Photo)
	TObjectPtr<UTexture2D> TextureCharacterPhoto;

	UFUNCTION()
	void SelectButtonClicked();

	//void SetUnselectedState() override;
	//void SetHoveredState() override;
	//void SetUnhoveredState() override;
	void Select() override;

protected:

	void NativeConstruct() override;

	UPROPERTY( meta = (BindWidget) )
	TObjectPtr<UTextBlock> TextCharacterName;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UButton> ButtonSelect;

	UPROPERTY( meta = (BindWidget) )
	TObjectPtr<UImage> ImageCharacterPhoto;

private:
	FName RowName;
};
