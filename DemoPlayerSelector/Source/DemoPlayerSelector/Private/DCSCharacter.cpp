// Fill out your copyright notice in the Description page of Project Settings.


#include "DCSCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Components/AudioComponent.h"

ADCSCharacter::ADCSCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

}

void ADCSCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ADCSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
}

void ADCSCharacter::PlayAudio(EPreviewMovementType MovementType)
{
	//if (CurrentAudio) CurrentAudio->SetActive(false);

	switch (MovementType)
	{
	case EPreviewMovementType::PM_Idle:
		//CurrentAudio = 
		UGameplayStatics::SpawnSound2D(this, AudioIdle);
		break;
	case EPreviewMovementType::PM_Walk:
		//CurrentAudio = 
		UGameplayStatics::SpawnSound2D(this, AudioWalk);
		break;
	case EPreviewMovementType::PM_Run:
		//CurrentAudio = 
		UGameplayStatics::SpawnSound2D(this, AudioRun);
		break;
	case EPreviewMovementType::PM_Gesture1:
		//CurrentAudio = 
		UGameplayStatics::SpawnSound2D(this, AudioEmote1);
		break;
	case EPreviewMovementType::PM_Gesture2:
		//CurrentAudio = 
		UGameplayStatics::SpawnSound2D(this, AudioEmote2);
		break;
	case EPreviewMovementType::PM_Spawn:
		//CurrentAudio = 
		UGameplayStatics::SpawnSound2D(this, AudioSpawn);
		break;
	default:
		break;
	}
}

void ADCSCharacter::StopAudio()
{
	//if (CurrentAudio) CurrentAudio->
}
