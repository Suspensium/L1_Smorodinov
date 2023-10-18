// Fill out your copyright notice in the Description page of Project Settings.


#include "StraightMovableShape.h"

void AStraightMovableShape::Move(const FVector& Direction, float DeltaTime)
{
	// Apply force to mesh to move it
	ColliderComponent->AddForce(MovementSpeed * FORCE_MODIFIER * Direction * DeltaTime);
}