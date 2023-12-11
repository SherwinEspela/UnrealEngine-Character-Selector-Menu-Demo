// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/PreviewMovementButtonWidget.h"
#include "Components/Button.h"

void UPreviewMovementButtonWidget::NativeConstruct()
{
	Super::NativeConstruct();

	Button->OnClicked.AddDynamic(this, &UPreviewMovementButtonWidget::HandleButtonClicked);
}

void UPreviewMovementButtonWidget::HandleButtonClicked()
{
	OnPreviewMovmentButtonClicked.Broadcast();
}

void UPreviewMovementButtonWidget::Select()
{
	Super::Select();
	HandleButtonClicked();
}
