// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AItemBase.h"
#include "FragmenItem.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFragmentCollectedSignature, FName, FragmentID);
UCLASS()
class ENTREGASPRACTICAPEV2_API AFragmenItem : public AAItemBase
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AFragmenItem();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fragment")
	FName FragmentID;

	// El delegado que avisará al mundo cuando se recolecte
	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnFragmentCollectedSignature OnFragmentCollected;

	virtual void Interact_Implementation(AActor* Interactor) override;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
