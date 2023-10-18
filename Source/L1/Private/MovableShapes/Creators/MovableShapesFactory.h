// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../Shapes/BaseMovableShape.h"
#include "MovableShapesFactory.generated.h"

UCLASS(Abstract)
class AMovableShapesFactory : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMovableShapesFactory();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Creation")
	ABaseMovableShape* CreateShape(AActor* EndPoint);
	virtual ABaseMovableShape* CreateShape_Implementation(AActor* EndPoint)
		PURE_VIRTUAL(AMovableShapesFactory::CreateShape, return nullptr;);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};