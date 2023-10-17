// Fill out your copyright notice in the Description page of Project Settings.


#include "MovableShapes/StraightMovableShape.h"

void AStraightMovableShape::Move(const FVector& Direction, float DeltaTime)
{
	// Apply force to mesh to move it
	ColliderComponent->AddForce(MovementSpeed * SPEED_MODIFIER * Direction * DeltaTime);
}