// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AItemBase.h"
#include "DamageItem.generated.h"

UCLASS()
class ENTREGASPRACTICAPEV2_API ADamageItem : public AAItemBase
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADamageItem();
	UPROPERTY(EditAnywhere, Category = "Damage")
	float CantDanio = 10.0f;

	virtual void Interact_Implementation(AActor* Interactor) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
