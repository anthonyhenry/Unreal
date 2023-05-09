// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

//private is where you initialize stuff that belongs only to this class. Cannot be accessed outside of the class
private:

	//Vector for the location that the platform starts at
	FVector StartLocation;

	//Vector that moves the platform
	UPROPERTY(EditAnywhere, Category="Moving")
	FVector PlatformVelocity = FVector(0,100,0);
	
	//Specifies how far the platform should move
	UPROPERTY(EditAnywhere, Category="Moving")
	float MoveDistance = 100;

	UPROPERTY(EditAnywhere, Category="Rotation")
	FRotator RotationVelocity;

	void MovePlatform(float DeltaTime);

	void RotatePlatform(float DeltaTime);

	bool ShouldPlatformReturn() const;

	float GetDistanceMoved() const;

};
