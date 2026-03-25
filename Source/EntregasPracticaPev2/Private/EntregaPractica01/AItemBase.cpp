// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/EntregaPractica01/AItemBase.h"


// Sets default values
AAItemBase::AAItemBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AAItemBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAItemBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAItemBase::Interact_Implementation(AActor* Interactor)
{
	
}
