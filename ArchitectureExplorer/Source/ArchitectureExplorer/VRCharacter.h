// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "VRCharacter.generated.h"

UCLASS()
class ARCHITECTUREEXPLORER_API AVRCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AVRCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
private:
	void UpdateDestinationMarker();
	bool FindTeleportDestination(TArray<FVector> &OutPath, FVector &OutLocation);
	void UpdateBlinkers();
	void UpdateSplines(const TArray<FVector> &Path);
	FVector2D GetBlinkerCenter();

	void MoveForward(float throttle);
	void MoveRight(float throttle);
	void BeginTeleport();

	void TeleportFinish();

	void StartFade(float FromAlpha, float ToAlpha);
private:

	UPROPERTY()
	class UCameraComponent* Camera = nullptr;

	UPROPERTY()
	class UMotionControllerComponent* LeftController = nullptr;
	UPROPERTY()
	UMotionControllerComponent* RightController = nullptr;

	UPROPERTY(EditAnywhere, Category = "Teleportation")
	class USplineComponent* TeleportPath;

	
	UPROPERTY()
	class USceneComponent* VRRoot = nullptr;
	
	UPROPERTY()
	class UStaticMeshComponent* DestinationMarker = nullptr;
	
	UPROPERTY()
	class UPostProcessComponent* PostProcessComponent = nullptr;



private:
	UPROPERTY(EditAnywhere)
	class UMaterialInterface* BlinkerMaterialBase = nullptr;

	UPROPERTY()
	class UMaterialInstanceDynamic* BlinkerMaterialInstance = nullptr;

	UPROPERTY(EditAnywhere)
	class UCurveFloat* RadiusVsVelocity = nullptr;

	UPROPERTY(EditAnywhere , Category="Teleportation")
	float TelportProjectileSpeed = 800.0f;

	UPROPERTY(EditAnywhere, Category = "Teleportation")
	float TeleportProjectileRadius = 10.0f;

	UPROPERTY(EditAnywhere, Category = "Teleportation")
	float TeleportSimulationTime = 2.0f;

	UPROPERTY(EditAnywhere)
	float FadeDuration = 1.0f;
	
	UPROPERTY(EditAnywhere)
	FVector TeleportProjectionExtent = FVector(100, 100, 100);



};
