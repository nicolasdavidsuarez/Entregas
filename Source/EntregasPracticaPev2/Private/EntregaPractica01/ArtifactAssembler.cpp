// Fill out your copyright notice in the Description page of Project Settings.


#include "EntregaPractica01/ArtifactAssembler.h"

#include "EntregaPractica01/AItemBase.h"
#include "Kismet/GameplayStatics.h"
class AFragmenItem;

// Sets default values
AArtifactAssembler::AArtifactAssembler()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AArtifactAssembler::Interact_Implementation(AActor* Interactor)
{
	IInteractableInterface::Interact_Implementation(Interactor);
}

void AArtifactAssembler::HandleFragmentCollected(FName FragmentID)
{
}

void AArtifactAssembler::FinalAction()
{
}

// Called when the game starts or when spawned
void AArtifactAssembler::BeginPlay()
{
	Super::BeginPlay();
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AAItemBase::StaticClass(),Fragments );
	
	
}

// Called every frame
void AArtifactAssembler::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

