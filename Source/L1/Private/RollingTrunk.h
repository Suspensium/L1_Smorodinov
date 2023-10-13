// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectPtr.h"
#include "GameFramework/Actor.h"
#include "RollingTrunk.generated.h"

UCLASS()
class ARollingTrunk : public AActor
{
	GENERATED_BODY()

	FTimerHandle TrunkSpawnHandle{};

	UPROPERTY(EditAnywhere)
	// How often in seconds should trunks spawn
	float SpawnTime{ 5.f };
	UPROPERTY(EditDefaultsOnly)
	// Trunk actor
	TSubclassOf<AActor> Actor;

	// Smart pointer to spawned actor
	TObjectPtr<AActor> SpawnedTrunk{ nullptr };

	// Spawn a trunk, removing previous one
	void SpawnTrunkOverTime();

public:
	// Sets default values for this actor's properties
	ARollingTrunk();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
