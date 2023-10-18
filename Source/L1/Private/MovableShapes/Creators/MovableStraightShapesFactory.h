// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MovableShapesFactory.h"
#include "MovableStraightShapesFactory.generated.h"

UCLASS()
class AMovableStraightShapesFactory : public AMovableShapesFactory
{
	GENERATED_BODY()

public:
	virtual ABaseMovableShape* CreateShape_Implementation(AActor* EndPoint) override;
};
