// Fill out your copyright notice in the Description page of Project Settings.


#include "MovableShapesFactory.h"
#include <Kismet/GameplayStatics.h>

// Sets default values
AMovableShapesFactory::AMovableShapesFactory()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

AMovableShapesFactory* AMovableShapesFactory::GetFactory(const TSubclassOf<AMovableShapesFactory>&FactoryClass, const UWorld * World)
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

bool AMovableShapesFactory::SpawnMovableShapeActor(const TSubclassOf<AMovableShapesFactory>& FactoryClass, const UWorld* World, AActor* EndPointActor)
{
	if (!FactoryClass || !World || !EndPointActor) return false;

	TObjectPtr<AMovableShapesFactory> Factory = GetFactory(FactoryClass, World);

	if (Factory)
	{
		TObjectPtr<ABaseMovableShape> NewShape = Factory->CreateShape(EndPointActor);
		if (!NewShape)
		{
			// If no implementation in blueprints use C++
			NewShape = Factory->CreateShape_Implementation(EndPointActor);
			if (!NewShape) return false;
		}
	}
	else
		return false;

	return true;
}

// Called when the game starts or when spawned
void AMovableShapesFactory::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMovableShapesFactory::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}