// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "PreviewMovement.h"
#include "DCSAnimInstance.generated.h"

class ADCSCharacter;

/**
 * 
 */
UCLASS()
class DEMOPLAYERSELECTOR_API UDCSAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	virtual void NativeBeginPlay() override;
	
private:
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	EPreviewMovementType PreviewMovementType = EPreviewMovementType::PM_Idle;
	
	UFUNCTION()
	void HandlePreviewMovementTypeChanged();
	
	TObjectPtr<ADCSCharacter> Character;
};
