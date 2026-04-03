// Fill out your copyright notice in the Description page of Project Settings.


#include "HealtModifier.h"

#include "HealtComponent.h"
#include "Components/BoxComponent.h"


// Sets default values
AHealtModifier::AHealtModifier()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
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
	OtherHealtComponent = nullptr;
}

void AHealtModifier::AplyModifier()
{
	if (bIsHealt)
	{
		OtherHealtComponent->TakeDamage(amount);
		GEngine->AddOnScreenDebugMessage(-1,1.f,FColor::Green,"Health");

	}else
	{
		OtherHealtComponent->TakeDamage(-amount);
		GEngine->AddOnScreenDebugMessage(-1,1.f,FColor::Red,"Damaged");

	}
}

// Called when the game starts or when spawned
void AHealtModifier::BeginPlay()
{
	Super::BeginPlay();
	VolumenModifier=CreateDefaultSubobject<UBoxComponent>("VolumenModifier");
	VolumenModifier->SetBoxExtent(FVector(250.0f, 250.0f, 250.0f));
	if (bIsHealt)
	{
		VolumenModifier->SetOverlayColor(FColor::Green);
	}else
	{
		VolumenModifier->SetOverlayColor(FColor::Red);
	}
	VolumenModifier->MarkRenderStateDirty();
}

// Called every frame
void AHealtModifier::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

