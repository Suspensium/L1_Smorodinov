// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseMovableShape.h"
#include "SineMovableShape.generated.h"

UCLASS()
class ASineMovableShape : public ABaseMovableShape
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category = "Movement")
	float Amplitude{ 10.f };

	UPROPERTY(EditAnywhere, Category = "Movement")
	float Frequency{ 5.f };

	virtual void Move(const FVector& Direction, float DeltaTime) override;

public:
	ASineMovableShape();
};