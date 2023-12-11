// Fill out your copyright notice in the Description page of Project Settings.


#include "DCSPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "UI/HUD/PlayerSelectorHUD.h"
#include "Widget/ButtonsWidget.h"
#include "Kismet/GameplayStatics.h"

void ADCSPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UEnhancedInputLocalPlayerSubsystem* PlayerSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	PlayerSubsystem->AddMappingContext(InputMappingContextPlayer, 0);

	PlayerSelectorHUD = Cast<APlayerSelectorHUD>(GetHUD());
}

void ADCSPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(InputActionDPadLeft, ETriggerEvent::Triggered, this, &ADCSPlayerController::DPadLeftTapped);
	EnhancedInputComponent->BindAction(InputActionDPadRight, ETriggerEvent::Triggered, this, &ADCSPlayerController::DPadRightTapped);
	EnhancedInputComponent->BindAction(InputActionDPadUp, ETriggerEvent::Triggered, this, &ADCSPlayerController::DPadUpTapped);
	EnhancedInputComponent->BindAction(InputActionDPadDown, ETriggerEvent::Triggered, this, &ADCSPlayerController::DPadDownTapped);
	EnhancedInputComponent->BindAction(InputActionButtonA, ETriggerEvent::Triggered, this, &ADCSPlayerController::ButtonATapped);
	EnhancedInputComponent->BindAction(InputActionReloadLevel, ETriggerEvent::Triggered, this, &ADCSPlayerController::ReloadLevel);
}

void ADCSPlayerController::DPadLeftTapped()
{
	if (PlayerSelectorHUD)
	{
		PlayerSelectorHUD->GetCurrentNavigationWidget()->MoveLeft();
	}
}

void ADCSPlayerController::DPadRightTapped()
{
	if (PlayerSelectorHUD)
	{
		PlayerSelectorHUD->GetCurrentNavigationWidget()->MoveRight();
	}
}

void ADCSPlayerController::DPadUpTapped()
{
	if (PlayerSelectorHUD)
	{
		PlayerSelectorHUD->GetCurrentNavigationWidget()->MoveUp();
	}
}

void ADCSPlayerController::DPadDownTapped()
{
	if (PlayerSelectorHUD)
	{
		PlayerSelectorHUD->GetCurrentNavigationWidget()->MoveDown();
	}
}

void ADCSPlayerController::ButtonATapped()
{
	if (PlayerSelectorHUD)
	{
		PlayerSelectorHUD->GetCurrentNavigationWidget()->Select();
	}
}

void ADCSPlayerController::ReloadLevel()
{
	UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
}
