// Fill out your copyright notice in the Description page of Project Settings.


#include "EntregaPractica01/ArtifactAssembler.h"

#include "StateTreeTypes.h"
#include "Components/SphereComponent.h"
#include "EntregaPractica01/AItemBase.h"
#include "EntregaPractica01/FragmenItem.h"
#include "Kismet/GameplayStatics.h"
class AFragmenItem;

// Sets default values
AArtifactAssembler::AArtifactAssembler()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;
	Sphere=CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->SetupAttachment(Mesh);
	Sphere->SetSphereRadius(150.0f);
	Sphere->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
}

void AArtifactAssembler::Interact_Implementation(AActor* Interactor)
{
	// Si no tenemos todos los fragmentos, o si el Timer ya está corriendo, no hacemos nada
	if (!bCanBeAssemble || GetWorldTimerManager().IsTimerActive(ArtifactTimerHandle))
	{
		UE_LOG(LogTemp, Error, TEXT("Aún te faltan fragmentos o ya se está ensamblando."));
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("Iniciando secuencia de ensamblaje (Espere 3 segundos)..."));

	
	GetWorld()->GetTimerManager().SetTimer(
		ArtifactTimerHandle, 
		this, 
		&AArtifactAssembler::FinalAction, 
		3.0f, 
		false
	);

	
}

void AArtifactAssembler::HandleFragmentCollected(FName FragmentID)
{
	CollectedCount++;
	
	if (CollectedCount >= TotalFragmentsInLevel && TotalFragmentsInLevel > 0)
	{
		bCanBeAssemble = true;
        
		GEngine->AddOnScreenDebugMessage(-1,3.0f,FColor::Red,"Todos los fragmentos recolectados! El artefacto puede ensamblarse");
	
	}
}

void AArtifactAssembler::FinalAction()
{
	GEngine->AddOnScreenDebugMessage(-1,3.0f, FColor::Green, "FinalAction, ¡BUM! Artefacto reconstruido con éxito!!!");

}

// Called when the game starts or when spawned
void AArtifactAssembler::BeginPlay()
{
	Super::BeginPlay();
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AFragmenItem::StaticClass(),Fragments );
	
	for (AActor* Actor:Fragments)
	{
		AFragmenItem* Fragment=Cast<AFragmenItem>(Actor);
		if (Fragment)
		{
			Fragment->OnFragmentCollected.AddDynamic(this,&AArtifactAssembler::HandleFragmentCollected);
			TotalFragmentsInLevel++;
		}
	}
}

// Called every frame
void AArtifactAssembler::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

