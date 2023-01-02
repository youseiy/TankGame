// Fill out your copyright notice in the Description page of Project Settings.


#include "TankGameMode.h"
#include "Tank.h"
#include "TankPlayerController.h"
#include "Tower.h"
#include "Kismet/GameplayStatics.h"


void ATankGameMode::BeginPlay()
{
	Super::BeginPlay();
	
	HandleGameStart();
}


void ATankGameMode::ActorDied(AActor* DeadActor)
{
	if (DeadActor == Tank)
	{
		Tank->HandleDestruction();
		if (TankPController)
		{
			TankPController->SetPlayerEnableState(false);
			
		}
		GameOver(false);
	}
	else if (ATower* DestroyedTower = Cast<ATower>(DeadActor))
	{
		
		DestroyedTower->HandleDestruction();
		TargetTowers--;
		if (TargetTowers ==0)
		{
			GameOver(true);
		}
	}
	
}

int32 ATankGameMode::GetTowerCount ()
{
	TArray<AActor*> Towers;
	UGameplayStatics::GetAllActorsOfClass(this,ATower::StaticClass(),Towers);
	return Towers.Num();
}

void ATankGameMode::HandleGameStart()
{
	TargetTowers=GetTowerCount();
	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this,0));
	TankPController= Cast<ATankPlayerController>(UGameplayStatics::GetPlayerController(this,0));

	StartGame();
	if (TankPController)
	{
		TankPController->SetPlayerEnableState(false);

		FTimerHandle PlayerEnableTimerHandle;

		FTimerDelegate PlayerEnableTimerDelegate = FTimerDelegate::CreateUObject(
			TankPController,
			&ATankPlayerController::SetPlayerEnableState,
			true);
		GetWorldTimerManager().SetTimer(PlayerEnableTimerHandle,
			PlayerEnableTimerDelegate,
			StartDelay,
			false);
		
	}
}
