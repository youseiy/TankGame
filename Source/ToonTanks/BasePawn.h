// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,meta=(AllowPrivateAccess = "true"))
	class UCapsuleComponent* CapsuleComp;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly,meta=(AllowPrivateAccess = "true"))
	UStaticMeshComponent* BaseMesh;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly,meta=(AllowPrivateAccess = "true"))
	UStaticMeshComponent* TurretMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly,meta=(AllowPrivateAccess = "true"))
	USceneComponent* SpawnProjectile;
    UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class AProjectile> ProjectileClass;
public:
	// Sets default values for this pawn's properties
	ABasePawn();
	void HandleDestruction();

protected:
	void RotateTurret(FVector LookAtTarget);
	void Fire();
	

};
