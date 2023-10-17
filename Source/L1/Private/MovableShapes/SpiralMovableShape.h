// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseMovableShape.h"
#include "SpiralMovableShape.generated.h"

UCLASS()
class ASpiralMovableShape : public ABaseMovableShape
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category = "Movement")
	float Radius{ 300.f };

	UPROPERTY(EditAnywhere, Category = "Movement")
	float RotationSpeed{ 300.f };

	virtual void BeginPlay() override;

	virtual void Move(const FVector& Direction, float DeltaTime) override;

public:
	ASpiralMovableShape();
};