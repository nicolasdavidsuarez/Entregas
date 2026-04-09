// Fill out your copyright notice in the Description page of Project Settings.


#include "HealtComponent.h"
#include "Net/UnrealNetwork.h"


// Sets default values for this component's properties
UHealtComponent::UHealtComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHealtComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UHealtComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHealtComponent::TakeDamage(int32 amount)
{
	CurretnHealt=CurretnHealt+amount;
	OnTakeDamage.Broadcast(CurretnHealt);
}

int32 UHealtComponent::GetMaxHealth()
{
	return MaxHealt;
}

int32 UHealtComponent::GetCurrentHealth()
{
	return CurretnHealt;
}

void UHealtComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UHealtComponent, CurretnHealt);
}

void UHealtComponent::OnRep_CurrentHealth()
{
	OnTakeDamage.Broadcast(0);
}

