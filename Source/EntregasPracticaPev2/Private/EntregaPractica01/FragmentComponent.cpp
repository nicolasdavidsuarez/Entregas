// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/EntregaPractica01/FragmentComponent.h"


// Sets default values for this component's properties
UFragmentComponent::UFragmentComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UFragmentComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UFragmentComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                       FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UFragmentComponent::AddFragment(FName FragmentID)
{
	if (!CollectedFragments.Contains(FragmentID))
	{
		CollectedFragments.Add(FragmentID);
	}
}

bool UFragmentComponent::IsArtifactComplete(int32 TotalRequired) const
{
	return CollectedFragments.Num() >= TotalRequired;
}

