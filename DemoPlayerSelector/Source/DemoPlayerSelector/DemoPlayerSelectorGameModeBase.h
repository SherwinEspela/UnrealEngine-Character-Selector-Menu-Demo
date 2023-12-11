// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DemoPlayerSelectorGameModeBase.generated.h"

class AAvatarSelectorActor;
class USoundBase;

/**
 * 
 */
UCLASS()
class DEMOPLAYERSELECTOR_API ADemoPlayerSelectorGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

protected:
	void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	USoundBase* SoundMusic;

//private:
//	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
//	TSubclassOf<AAvatarSelectorActor> AvatarSelector;
};
