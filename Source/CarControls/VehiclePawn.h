// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehicle.h"
#include "VehiclePawn.generated.h"

/**
 * 
 */
UCLASS()
class CARCONTROLS_API AVehiclePawn : public AWheeledVehicle
{
	GENERATED_BODY()

public:
	AVehiclePawn();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/**Throttle/Steering*/
	void ApplyThrottle(float Val);
	void ApplySteering(float Val);

	/**Look Around*/
	void LookUp(float Val);
	void Turn(float Val);

	/**Handbrakes*/
	void OnBreakPressed();
	void OnBreakReleased();

	/**Update InAir Physics*/
	void UpdateAirControll(float DeltaTime);

protected:

	/**Spring Arm*/
	UPROPERTY(Category = "Camera", EditDefaultsOnly, meta = (AllowPrivateAcess = "true"))
	class USpringArmComponent* SpringArm;

	/**Camera*/
	UPROPERTY(Category = "Camera", EditDefaultsOnly, meta = (AllowPrivateAcess = "true"))
	class UCameraComponent* Camera;

};
