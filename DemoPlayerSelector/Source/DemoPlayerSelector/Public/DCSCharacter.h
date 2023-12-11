// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PreviewMovement.h"
#include "DCSCharacter.generated.h"

class USoundBase;
class UAudioComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPreviewMovementTypeChanged);

UCLASS()
class DEMOPLAYERSELECTOR_API ADCSCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ADCSCharacter();
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	FORCEINLINE void SetPreviewMovementType(EPreviewMovementType NewType) { 
		PreviewMovementType = NewType;
		OnPreviewMovementTypeChanged.Broadcast();
	}
	
	UFUNCTION(BlueprintCallable)
	FORCEINLINE EPreviewMovementType GetPreviewMovementType() const { return PreviewMovementType; }

	UPROPERTY(BlueprintAssignable)
	FPreviewMovementTypeChanged OnPreviewMovementTypeChanged;

	UFUNCTION(BlueprintCallable)
	void PlayAudio(EPreviewMovementType MovementType);

	UFUNCTION(BlueprintCallable)
	void StopAudio();

protected:
	virtual void BeginPlay() override;

private:
	EPreviewMovementType PreviewMovementType = EPreviewMovementType::PM_Spawn;

	/*
	* Avatar Audios
	*/
	UPROPERTY(EditAnywhere, Category = "Avatar | Audio")
	TObjectPtr<USoundBase> AudioSpawn;

	UPROPERTY(EditAnywhere, Category = "Avatar | Audio")
	TObjectPtr<USoundBase> AudioIdle;

	UPROPERTY(EditAnywhere, Category = "Avatar | Audio")
	TObjectPtr<USoundBase> AudioWalk;

	UPROPERTY(EditAnywhere, Category = "Avatar | Audio")
	TObjectPtr<USoundBase> AudioRun;

	UPROPERTY(EditAnywhere, Category = "Avatar | Audio")
	TObjectPtr<USoundBase> AudioEmote1;

	UPROPERTY(EditAnywhere, Category = "Avatar | Audio")
	TObjectPtr<USoundBase> AudioEmote2;

	TObjectPtr<UAudioComponent> CurrentAudio;
};
