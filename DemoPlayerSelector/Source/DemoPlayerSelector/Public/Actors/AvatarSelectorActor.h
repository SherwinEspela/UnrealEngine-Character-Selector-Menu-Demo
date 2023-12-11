// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AvatarSelectorActor.generated.h"

class ADCSCharacter;

UCLASS()
class DEMOPLAYERSELECTOR_API AAvatarSelectorActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AAvatarSelectorActor();

	void DisplaySelectedAvatar(FName RowName);

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category = "Avatar")
	TArray<TSubclassOf<ADCSCharacter>> Avatars;

	ADCSCharacter* CurrentAvatar;
};
