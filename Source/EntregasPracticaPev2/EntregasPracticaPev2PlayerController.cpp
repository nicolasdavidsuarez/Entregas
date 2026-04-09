// Copyright Epic Games, Inc. All Rights Reserved.


#include "EntregasPracticaPev2PlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "InputMappingContext.h"
#include "Blueprint/UserWidget.h"
#include "EntregasPracticaPev2.h"
#include "EntregasPracticaPev2Character.h"
#include "UserWidgetHud.h"
#include "Components/ProgressBar.h"
#include "Widgets/Input/SVirtualJoystick.h"

void AEntregasPracticaPev2PlayerController::BeginPlay()
{
	Super::BeginPlay();

	// only spawn touch controls on local player controllers
	if (SVirtualJoystick::ShouldDisplayTouchInterface() && IsLocalPlayerController())
	{
		// spawn the mobile controls widget
		MobileControlsWidget = CreateWidget<UUserWidget>(this, MobileControlsWidgetClass);

		if (MobileControlsWidget)
		{
			// add the controls to the player screen
			MobileControlsWidget->AddToPlayerScreen(0);

		} else {

			UE_LOG(LogEntregasPracticaPev2, Error, TEXT("Could not spawn mobile controls widget."));

		}

	}

	if (IsLocalController() && HUDWidgetClass)
	{
		CurrentHUD = CreateWidget<UUserWidgetHud>(this, HUDWidgetClass);
		if (CurrentHUD)
		{
			CurrentHUD->AddToViewport();
		}
	}
	
}

void AEntregasPracticaPev2PlayerController::ActualizarHUD(int32 amount)
{
	
	AEntregasPracticaPev2Character* MiChar = Cast<AEntregasPracticaPev2Character>(GetPawn());
    
	if (CurrentHUD && MiChar && MiChar->HealtComponent)
	{
		float Porcentaje = (float)MiChar->HealtComponent->GetCurrentHealth() / (float)MiChar->HealtComponent->GetMaxHealth();
        
		if (CurrentHUD->HealthBar)
		{
			CurrentHUD->HealthBar->SetPercent(Porcentaje);
		}
        
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("HUD actualizado desde PC: %f"), Porcentaje));
	}
}

void AEntregasPracticaPev2PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// only add IMCs for local player controllers
	if (IsLocalPlayerController())
	{
		// Add Input Mapping Contexts
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
		{
			for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
			{
				Subsystem->AddMappingContext(CurrentContext, 0);
			}

			// only add these IMCs if we're not using mobile touch input
			if (!SVirtualJoystick::ShouldDisplayTouchInterface())
			{
				for (UInputMappingContext* CurrentContext : MobileExcludedMappingContexts)
				{
					Subsystem->AddMappingContext(CurrentContext, 0);
				}
			}
		}
	}
}

void AEntregasPracticaPev2PlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	AEntregasPracticaPev2Character* MiChar = Cast<AEntregasPracticaPev2Character>(InPawn);
	if (MiChar && MiChar->HealtComponent)
	{
		// El Controller se suscribe al componente del Character que acaba de tomar
		MiChar->HealtComponent->OnTakeDamage.AddDynamic(this, &AEntregasPracticaPev2PlayerController::ActualizarHUD);
        
		// Actualización inicial
		ActualizarHUD(0);
	}
}
