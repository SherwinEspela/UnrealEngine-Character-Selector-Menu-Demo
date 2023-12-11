// Copyright Epic Games, Inc. All Rights Reserved.


#include "DemoPlayerSelectorGameModeBase.h"
#include "Sound/SoundBase.h"
#include "Kismet/GameplayStatics.h"

void ADemoPlayerSelectorGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	UGameplayStatics::PlaySound2D(this, SoundMusic);
}
