// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MovableShapes/BaseMovableShape.h"
#include "StraightMovableShape.generated.h"

UCLASS()
class AStraightMovableShape : public ABaseMovableShape
{
	GENERATED_BODY()

private:
	const float FORCE_MODIFIER{ 100000.f };

	virtual void Move(const FVector& Direction, float DeltaTime) override;
};
