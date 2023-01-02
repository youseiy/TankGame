// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()
	
private:
	UPROPERTY(VisibleAnywhere, meta=(AllowPrivateAccess = "true"))
	class USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, meta=(AllowPrivateAccess = "true"))
	class UCameraComponent* Camera;
	UPROPERTY(EditAnywhere)
	float Speed = 200.f;
    UPROPERTY(EditAnywhere)
	float TurnSpeed;

	
	void Move(float value);
	void Turn(float Value);


	APlayerController* TankPlayerController;
	
public:
	ATank();
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void HandleDestruction();
	 APlayerController* GetTankPlayerController() const {return TankPlayerController;};
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};
