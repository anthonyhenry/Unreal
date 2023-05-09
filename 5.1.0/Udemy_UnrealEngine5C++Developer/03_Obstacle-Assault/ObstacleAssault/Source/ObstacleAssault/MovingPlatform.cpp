// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	//Set start location
	StartLocation = GetActorLocation();
	

}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);

	RotatePlatform(DeltaTime);
	
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	//Check if the platform has moved the specified distance
	if(ShouldPlatformReturn())
	{
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation = StartLocation + MoveDirection * MoveDistance;
		SetActorLocation(StartLocation);
		//Change direction
		PlatformVelocity = -PlatformVelocity;
	}
	else
	{
		//Add a vector to the current location
		FVector NewLocation = GetActorLocation() + (PlatformVelocity * DeltaTime);//Multiplying by DeltaTime makes this frame independent
		//Set the new location
		SetActorLocation(NewLocation);
	}
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	AddActorLocalRotation(RotationVelocity * DeltaTime);
}

bool AMovingPlatform::ShouldPlatformReturn() const
{
	return GetDistanceMoved() > MoveDistance;
}

float AMovingPlatform::GetDistanceMoved() const
{
	//Check how far we moved
	// :: is called a Scope Resolution Operator. It allows you to look at the functions inside a class
	//the Dist function in FVector returns the distance between two vectors
	return FVector::Dist(StartLocation, GetActorLocation());
}