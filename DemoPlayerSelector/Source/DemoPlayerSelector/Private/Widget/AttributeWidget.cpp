// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/AttributeWidget.h"
#include "Components/ProgressBar.h"

void UAttributeWidget::SetAttributeValue(float NewValue) {
	//if (ProgressBarAttribute) ProgressBarAttribute->SetPercent(NewValue);
	OnAttributeValueChanged(NewValue);
}