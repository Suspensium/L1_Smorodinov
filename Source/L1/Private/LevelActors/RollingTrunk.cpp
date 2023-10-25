// Fill out your copyright notice in the Description page of Project Settings.


#include "RollingTrunk.h"

void ARollingTrunk::SpawnTrunkOverTime()
{
	UWorld* World = GetWorld();
	if (!World) return;

	FTransform SpawnTransformation{ GetActorTransform() };

	// Spawn the Trunk Actor and push it to queue
	SpawnedTrunks.push(World->SpawnActor(Actor, &SpawnTransformation));

	if (TObjectPtr<UStaticMeshComponent> TrunkMesh = SpawnedTrunks.back()->FindComponentByClass<UStaticMeshComponent>())
	{
		// Add impulse to mesh
		TrunkMesh->AddImpulse(Impulse, NAME_None, true);
	}
}

void ARollingTrunk::DestroyTrunkOverTime()
{
	if (!SpawnedTrunks.empty())
		SpawnedTrunks.front()->Destroy();
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

	FTimerHandle TrunkSpawnHandle{};
	FTimerHandle TrunkDestructionHandle{};

	// Set timer to spawn trunk every SpawnTime seconds
	GetWorldTimerManager().SetTimer(TrunkSpawnHandle, this, &ARollingTrunk::SpawnTrunkOverTime, SpawnTime, true, 0.f);
	// Set timer to destroy trunk every DestroyTime seconds
	GetWorldTimerManager().SetTimer(TrunkDestructionHandle, this, &ARollingTrunk::DestroyTrunkOverTime, DestroyTime, true);
}

// Called every frame
void ARollingTrunk::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

