// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HealtComponent.h"
#include "GameFramework/Actor.h"
#include "HealtModifier.generated.h"

class UBoxComponent;

UCLASS()
class ENTREGASPRACTICAPEV2_API AHealtModifier : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AHealtModifier();

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;

	UFUNCTION()
	void AplyModifier();

	UPROPERTY()
	FTimerHandle TimerAplyModifyHandler;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Healt Modifier")
	int32 amount;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Healt Modifier")
	TObjectPtr<UBoxComponent> VolumenModifier;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Healt Modifier")
	bool bIsHealt = false;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Healt Modifier")
	UHealtComponent* OtherHealtComponent;
};
