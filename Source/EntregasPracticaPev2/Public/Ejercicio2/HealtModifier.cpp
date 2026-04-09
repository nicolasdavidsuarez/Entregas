// Fill out your copyright notice in the Description page of Project Settings.


#include "HealtModifier.h"

#include "EntregasPracticaPev2Character.h"
#include "HealtComponent.h"
#include "Components/BoxComponent.h"


// Sets default values
AHealtModifier::AHealtModifier()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	VolumenModifier=CreateDefaultSubobject<UBoxComponent>("VolumenModifier");
	VolumenModifier->SetBoxExtent(FVector(250.0f, 250.0f, 250.0f));

	SetRootComponent(VolumenModifier);
	
}

void AHealtModifier::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	if (UHealtComponent* HealtComponent=OtherActor->FindComponentByClass<UHealtComponent>())
	{
		OtherHealtComponent=HealtComponent;
		
			GetWorldTimerManager().SetTimer(TimerAplyModifyHandler,this,&AHealtModifier::AplyModifier,1.0f,true);
		
	}
}

void AHealtModifier::NotifyActorEndOverlap(AActor* OtherActor)
{
	Super::NotifyActorEndOverlap(OtherActor);
AEntregasPracticaPev2Character* actor=Cast<AEntregasPracticaPev2Character>(OtherActor);
	int cant= actor->getDamage();
	GEngine->AddOnScreenDebugMessage(-1,3.0f,FColor::Red,FString::Printf(TEXT("cantidad de veces que se Aplico Modificador: %d"),CantidadDeInteracciones));
	OtherHealtComponent = nullptr;
}

void AHealtModifier::AplyModifier()
{
	if (OtherHealtComponent)
	{
		if (bIsHealt)
		{
			OtherHealtComponent->TakeDamage(amount);
			GEngine->AddOnScreenDebugMessage(-1,10.0f,FColor::Green,FString::Printf(TEXT("Health: %d"),OtherHealtComponent->GetCurrentHealth()));

		}else
		{
			OtherHealtComponent->TakeDamage(-amount);
			GEngine->AddOnScreenDebugMessage(-1,10.0f,FColor::Red,FString::Printf(TEXT("Damaged: %d"),OtherHealtComponent->GetCurrentHealth()));
	
		}
		CantidadDeInteracciones++;
	}
}

// Called when the game starts or when spawned
void AHealtModifier::BeginPlay()
{
	Super::BeginPlay();
	if (bIsHealt)
	{
		//VolumenModifier->SetOverlayColor(FColor::Green);
		VolumenModifier->ShapeColor = FColor::Green;
	}else
	{
		VolumenModifier->ShapeColor=(FColor::Red);
	}
	VolumenModifier->MarkRenderStateDirty();
	
}

// Called every frame
void AHealtModifier::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

