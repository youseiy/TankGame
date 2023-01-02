// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePawn.h"

#include "Projectile.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABasePawn::ABasePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent=CapsuleComp;
	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));
	BaseMesh->SetupAttachment(CapsuleComp);

	TurretMesh=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TurretMesh"));
	TurretMesh->SetupAttachment(BaseMesh);

	SpawnProjectile = CreateDefaultSubobject<USceneComponent>(TEXT("Spawn Projectile"));
	SpawnProjectile->SetupAttachment(TurretMesh);

	
	
}


void ABasePawn::RotateTurret(FVector LookAtTarget)
{
	FVector ToTarget = LookAtTarget - TurretMesh->GetComponentLocation();
	FRotator LookAtRotation = FRotator(0.f,ToTarget.Rotation().Yaw,0.f);
	TurretMesh->SetWorldRotation(
		FMath::RInterpTo(
			TurretMesh->GetComponentRotation(),
			LookAtRotation,
			UGameplayStatics::GetWorldDeltaSeconds(this)
			,15.f));
	
}

void ABasePawn::Fire()
{
	FVector ProjectileSpawnPoint = SpawnProjectile->GetComponentLocation();
	DrawDebugSphere(GetWorld(),ProjectileSpawnPoint,20.f,12.f,FColor::Blue,false,3.f);
	FVector Location = SpawnProjectile->GetComponentLocation();
	FRotator Rotation = SpawnProjectile->GetComponentRotation();
	auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileClass,Location,Rotation);
	Projectile->SetOwner(this);
}

void ABasePawn::HandleDestruction()
{
	
}





