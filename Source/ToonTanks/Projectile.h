// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class TOONTANKS_API AProjectile : public AActor
{
	GENERATED_BODY()
private:
    UPROPERTY(VisibleAnywhere, meta=(AllowPrivateAccess = "true"))
	UStaticMeshComponent* ProjectileMesh;

	UPROPERTY(VisibleAnywhere, meta=(AllowPrivateAccess = "true"))
	class UProjectileMovementComponent* ProjectileMovementComp;
    UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit );
    UPROPERTY(EditAnywhere)
	float Damage = 50.f;
    UPROPERTY(EditAnywhere )
	class UParticleSystem* HitParticles;
	UPROPERTY(VisibleAnywhere)
	class UParticleSystemComponent* ParticleSysComponent;
    UPROPERTY(VisibleAnywhere)
	class USoundBase* LaunchSound;
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
