// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/EntregaPractica01/FragmenItem.h"

#include "Public/EntregaPractica01/FragmentComponent.h"


class UFragmentComponent;
// Sets default values
AFragmenItem::AFragmenItem()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AFragmenItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFragmenItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFragmenItem::Interact_Implementation(AActor* Interactor)
{
	
	if (UFragmentComponent* FragComp = Interactor->FindComponentByClass<UFragmentComponent>())
	{
		FragComp->AddFragment(FragmentID);
        		
		OnFragmentCollected.Broadcast(FragmentID);       
		
		Destroy();
	}
}