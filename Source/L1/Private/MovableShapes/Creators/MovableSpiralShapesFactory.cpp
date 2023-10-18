// Fill out your copyright notice in the Description page of Project Settings.


#include "MovableSpiralShapesFactory.h"
#include "../Shapes/SpiralMovableShape.h"

ABaseMovableShape* AMovableSpiralShapesFactory::CreateShape_Implementation(AActor* EndPoint)
{
	FTransform SpawnTransform = GetActorTransform();
	ABaseMovableShape* SpiralShape = GetWorld()->SpawnActor<ASpiralMovableShape>(ASpiralMovableShape::StaticClass(), SpawnTransform);
	SpiralShape->SetEndPoint(EndPoint);
	return SpiralShape;
}