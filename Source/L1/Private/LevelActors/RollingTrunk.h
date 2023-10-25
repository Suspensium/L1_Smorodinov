// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <queue>
#include "CoreMinimal.h"
#include "UObject/ObjectPtr.h"
#include "GameFramework/Actor.h"
#include "RollingTrunk.generated.h"

UCLASS()
class ARollingTrunk : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	// How often in seconds should trunks spawn
	float SpawnTime{ 5.f };
	UPROPERTY(EditAnywhere)
	// Time before trunk deletion
	float DestroyTime{ 6.f };
	UPROPERTY(EditAnywhere)
	// Starting impulse
	FVector Impulse{ 0., 0., -3000. };
	// Trunk actor
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AActor> Actor;

	// Pointers queue to actors spawned
	std::queue<TObjectPtr<AActor>> SpawnedTrunks{ };

	// Spawn a trunk, removing previous one
	void SpawnTrunkOverTime();
	void DestroyTrunkOverTime();

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
