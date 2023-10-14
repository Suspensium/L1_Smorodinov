// Fill out your copyright notice in the Description page of Project Settings.


#include "SpiralMovableShape.h"
#include "Components/SphereComponent.h"

void ASpiralMovableShape::BeginPlay()
{
	Super::BeginPlay();

	if (TObjectPtr<UStaticMeshComponent> Mesh = FindComponentByClass<UStaticMeshComponent>())
	{
		// Mesh offset
		FVector Offset = FVector(Radius, 0.f, 0.f);
		Mesh->AddLocalOffset(Offset);
	}
}

void ASpiralMovableShape::Move(const FVector& Direction, float DeltaTime)
{
	// Calculate the angle of rotation
	float RotationAngle = RotationSpeed * DeltaTime;

	FVector DirectionMovement = Direction * MovementSpeed * DeltaTime;
	FVector NewLocation = GetActorLocation() + DirectionMovement;

	// Calculate the rotation quaternion to represent the rotation
	FQuat RotationQuat = FQuat(Direction, FMath::DegreesToRadians(RotationAngle));

	AddActorLocalRotation(RotationQuat);
	SetActorLocation(NewLocation);
}

ASpiralMovableShape::ASpiralMovableShape() : Super()
{
	MovementSpeed = 300.f;
}