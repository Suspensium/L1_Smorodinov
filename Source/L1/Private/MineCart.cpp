// Fill out your copyright notice in the Description page of Project Settings.


#include "MineCart.h"

void AMineCart::FillCartWithActors(const TSet<TSubclassOf<AActor>>& Actors, int Count)
{
	UWorld* World{ GetWorld() };
	if (!World) return;

	FVector LocationOffset{};
	FVector Origin{};
	FVector ActorBounds{};
	// Random X axis in bounds of cart length
	double RandomX{};
	// Random Y axis in bounds of cart width
	double RandomY{};
	// Random Z axis from cart base and upward
	double RandomZ{};
	GetActorBounds(true, Origin, ActorBounds);
	FTransform ActorTransform{ GetActorTransform() };


	for (auto& Actor : Actors)
		for (int i = 0; i < Count; i++)
		{
			RandomX = FMath::RandRange(-ActorBounds.X / 8., ActorBounds.X / 8.);
			RandomY = FMath::RandRange(-ActorBounds.Y / 8., ActorBounds.Y / 8.);
			RandomZ = FMath::RandRange(3., 6.);

			LocationOffset = FVector(RandomX, RandomY, RandomZ);
			ActorTransform.AddToTranslation(LocationOffset);
			World->SpawnActor(Actor, &ActorTransform);
		}
}

// Sets default values
AMineCart::AMineCart()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AMineCart::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMineCart::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

