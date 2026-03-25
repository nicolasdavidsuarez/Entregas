// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableInterface.h"
#include "GameFramework/Actor.h"
#include "ArtifactAssembler.generated.h"

UCLASS()
class ENTREGASPRACTICAPEV2_API AArtifactAssembler : public AActor, public IInteractableInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AArtifactAssembler();
	virtual void Interact_Implementation(AActor* Interactor) override;

	UFUNCTION()
	void HandleFragmentCollected(FName FragmentID);

	void FinalAction();

private:
	int32 TotalFragmentsInLevel = 0;
	int32 CollectedCount = 0;
	bool bCanBeActivated = false;
	TArray<AActor*> Fragments;
	FTimerHandle ArtifactTimerHandle;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
};
