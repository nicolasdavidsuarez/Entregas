// Fill out your copyright notice in the Description page of Project Settings.


#include "EntregaPractica01/DamageItem.h"

#include "EntregasPracticaPev2Character.h"


// Sets default values
ADamageItem::ADamageItem()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ADamageItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADamageItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADamageItem::Interact_Implementation(AActor* Interactor)
{
	// Aplicamos daño al actor que interactuó
	AEntregasPracticaPev2Character* player = Cast<AEntregasPracticaPev2Character>(Interactor);
	if (player)
	{
		player->AplicarDanio(CantDanio);
	}
	Destroy();
}