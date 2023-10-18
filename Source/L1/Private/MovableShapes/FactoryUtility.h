// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

class FactoryUtility
{
public:
	static bool SpawnMovableShapeActor(const TSubclassOf<class AMovableShapesFactory>& FactoryClass, const UWorld* World, AActor* EndPointActor);
	static AMovableShapesFactory* GetFactory(const TSubclassOf<AMovableShapesFactory>& FactoryClass, const UWorld* World);
};
	