// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"

#include "Tank.h"
#include "Kismet/GameplayStatics.h"


ATower::ATower()
{
	
}
void ATower::BeginPlay()
{
	Super::BeginPlay();

	TankRef  = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this,0));

	GetWorldTimerManager().SetTimer(FireRateTimerHandle,this,&ATower::CheckFireCondition,FireRate,true);
	
}



void ATower::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	if (InFireRange())
	{
		RotateTurret(TankRef->GetActorLocation());
	}
	
}

void ATower::CheckFireCondition()
{
	if (InFireRange())
	{
		Fire();
	}
	
}

bool ATower::InFireRange()
{
	if (TankRef)
	{
		float const Distance= FVector::Dist(GetActorLocation(),TankRef->GetActorLocation());
		if (Distance<=FireRange)
		{
			return true;
		}
	}
	return false;
}

void ATower::HandleDestruction()
{
	Super::HandleDestruction();
	Destroy();
}

