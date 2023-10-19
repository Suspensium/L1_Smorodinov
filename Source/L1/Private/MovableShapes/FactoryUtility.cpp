// Fill out your copyright notice in the Description page of Project Settings.


#include "MovableShapes/FactoryUtility.h"
#include "Creators/MovableShapesFactory.h"
#include <Kismet/GameplayStatics.h>

bool FactoryUtility::SpawnMovableShapeActor(const TSubclassOf<AMovableShapesFactory>& FactoryClass, const UWorld* World, AActor* EndPointActor)
{
	if (!FactoryClass || !World || !EndPointActor) return false;

	AMovableShapesFactory* Factory = GetFactory(FactoryClass, World);

	if (Factory)
	{
		ABaseMovableShape* NewShape = Factory->CreateShape(EndPointActor);
		if (!NewShape)
		{
			// If no implementation in blueprints use C++
			NewShape = Factory->CreateShape_Implementation(EndPointActor);
			if (!NewShape) return false;
		}
#if WITH_EDITOR
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, TEXT("Spawn Actor"));
#endif
	}
	else
	{
#if WITH_EDITOR
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, TEXT("Factory not found"));
#endif
		return false;
	}

	return true;
}

AMovableShapesFactory* FactoryUtility::GetFactory(const TSubclassOf<AMovableShapesFactory>& FactoryClass, const UWorld* World)
{
	if (!FactoryClass || !World) return nullptr;

	TArray<AActor*> FactoryActors;
	UGameplayStatics::GetAllActorsOfClass(World, FactoryClass, FactoryActors);

	if (FactoryActors.Num() > 0)
	{
		return Cast<AMovableShapesFactory>(FactoryActors[0]);
	}

	return nullptr;
}