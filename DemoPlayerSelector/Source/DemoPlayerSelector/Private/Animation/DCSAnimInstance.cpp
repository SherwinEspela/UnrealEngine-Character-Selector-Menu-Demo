// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/DCSAnimInstance.h"
#include "DCSCharacter.h"

void UDCSAnimInstance::NativeBeginPlay()
{
	if (Character == nullptr)
	{
		APawn* PawnOwner = TryGetPawnOwner();
		if (PawnOwner)
		{
			Character = Cast<ADCSCharacter>(PawnOwner);
			Character->OnPreviewMovementTypeChanged.AddDynamic(this, &UDCSAnimInstance::HandlePreviewMovementTypeChanged);
		}
	}
}

void UDCSAnimInstance::HandlePreviewMovementTypeChanged()
{
	PreviewMovementType = Character->GetPreviewMovementType();
}
