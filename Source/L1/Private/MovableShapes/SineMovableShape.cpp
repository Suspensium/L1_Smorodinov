// Fill out your copyright notice in the Description page of Project Settings.


#include "SineMovableShape.h"
#include "Components/SphereComponent.h"

void ASineMovableShape::Move(const FVector& Direction, float DeltaTime)
{
	// Current phase of sine line by time
	float Phase = GetWorld()->GetTimeSeconds() * Frequency;

	// Sine wave offset from -1 to 1
	float Offset = Amplitude * 100.f * FMath::Sin(Phase);

	// Direction movement component
	FVector DirectionMovement = Direction * MovementSpeed * DeltaTime;

	// Calculate a perpendicular vector for the sine wave
	FVector PerpendicularVector = FVector(-Direction.Y, Direction.X, Direction.Z);

	//FVector InvertedDirection = FVector(-1.f) + Direction;

	// Sine wave movement
	//FVector SinusoidalMovement = InvertedDirection * FVector(Offset, Offset, 0) * DeltaTime;
	FVector SinusoidalMovement = PerpendicularVector * Offset * DeltaTime;

	FVector NewLocation = GetActorLocation() + DirectionMovement + SinusoidalMovement;

	SetActorLocation(NewLocation);
}

ASineMovableShape::ASineMovableShape() : Super()
{
	MovementSpeed = 300.f;
}
