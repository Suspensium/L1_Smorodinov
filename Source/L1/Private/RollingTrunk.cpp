// Fill out your copyright notice in the Description page of Project Settings.


#include "RollingTrunk.h"

void ARollingTrunk::SpawnTrunkOverTime()
{
	UWorld* World = GetWorld();
	if (!World) return;

	FTransform SpawnTransformation{ GetActorTransform() };

	// Remove the previous Trunk Actor
	if (SpawnedTrunk)
		SpawnedTrunk->Destroy();

	// Spawn the Trunk Actor
	SpawnedTrunk = World->SpawnActor(Actor, &SpawnTransformation);
}

// Sets default values
ARollingTrunk::ARollingTrunk()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARollingTrunk::BeginPlay()
{
	Super::BeginPlay();

	// Set timer to spawn trunk every SpawnTime seconds
	GetWorldTimerManager().SetTimer(TrunkSpawnHandle, this, &ARollingTrunk::SpawnTrunkOverTime, SpawnTime, true);
}

// Called every frame
void ARollingTrunk::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

