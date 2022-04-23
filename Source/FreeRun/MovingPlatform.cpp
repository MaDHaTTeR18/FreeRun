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
	StartPosition=GetActorLocation();
	CurrentPosition = StartPosition;
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	CurrentPosition = CurrentPosition+(PlatformVelocity * DeltaTime);
	SetActorLocation(CurrentPosition);
	float DistanceMoved = FVector::Dist(StartPosition,CurrentPosition);
	if (DistanceMoved>MoveDistance)
	{
		StartPosition = StartPosition+(PlatformVelocity.GetSafeNormal())*MoveDistance;
		SetActorLocation(StartPosition);
		PlatformVelocity=- PlatformVelocity;
	}

}
