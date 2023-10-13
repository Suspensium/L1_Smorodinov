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

	UPROPERTY(EditAnywhere, Category="Movement")
	float Amplitude{};

	UPROPERTY(EditAnywhere, Category = "Movement")
	float Frequency{};

	virtual void Move(float Amplitude, float Frequency, FVector Direction, float DeltaTime) override;
};