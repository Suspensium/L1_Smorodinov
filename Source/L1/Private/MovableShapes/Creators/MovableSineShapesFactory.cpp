// Fill out your copyright notice in the Description page of Project Settings.


#include "MovableSineShapesFactory.h"
#include "../Shapes/SineMovableShape.h"

ABaseMovableShape* AMovableSineShapesFactory::CreateShape_Implementation(AActor* EndPoint)
{
	FTransform SpawnTransform = GetActorTransform();
	ABaseMovableShape* SineShape = GetWorld()->SpawnActor<ASineMovableShape>(ASineMovableShape::StaticClass(), SpawnTransform);
	SineShape->SetEndPoint(EndPoint);
	return SineShape;
}