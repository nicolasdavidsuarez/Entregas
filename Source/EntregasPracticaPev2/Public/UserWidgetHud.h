// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UserWidgetHud.generated.h"

/**
 * 
 */
UCLASS()
class ENTREGASPRACTICAPEV2_API UUserWidgetHud : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

public:
	UPROPERTY(meta = (BindWidget))
	class UProgressBar* HealthBar;
	
};
