// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealtComponent.generated.h"
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTakeDamage, int32, amount);


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ENTREGASPRACTICAPEV2_API UHealtComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UHealtComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	void TakeDamage(int32 amount);
	
	UPROPERTY(EditAnywhere)
	FOnTakeDamage OnTakeDamage;
	
	private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category="Healt" ,meta = (AllowPrivateAccess = "true"))
	int32 CurretnHealt=100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category="Healt" ,meta = (AllowPrivateAccess = "true"))
	int32 MaxHealt=100;
};
