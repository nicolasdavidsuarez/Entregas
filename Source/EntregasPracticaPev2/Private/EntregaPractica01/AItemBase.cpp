// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/EntregaPractica01/AItemBase.h"

#include "Components/SphereComponent.h"


// Sets default values
AAItemBase::AAItemBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;
	Sphere->SetupAttachment(Mesh);
	Sphere->SetSphereRadius(150.0f);
Sphere->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
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
