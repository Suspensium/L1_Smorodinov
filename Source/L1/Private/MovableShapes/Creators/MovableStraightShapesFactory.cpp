// Fill out your copyright notice in the Description page of Project Settings.


#include "MovableStraightShapesFactory.h"
#include "../Shapes/StraightMovableShape.h"

ABaseMovableShape* AMovableStraightShapesFactory::CreateShape_Implementation(AActor* EndPoint)
{
	FTransform SpawnTransform = GetActorTransform();
	ABaseMovableShape* StraightShape = GetWorld()->SpawnActor<AStraightMovableShape>(AStraightMovableShape::StaticClass(), SpawnTransform);
	StraightShape->SetEndPoint(EndPoint);
	return StraightShape;
}