// Fill out your copyright notice in the Description page of Project Settings.


#include "MineCart.h"

void AMineCart::FillCartWithActors(const TSet<TSubclassOf<AActor>>& Actors, int Count)
{
	if (!bFilled) return;

	UWorld* World{ GetWorld() };
	if (!World) return;

	FVector LocationOffset{};
	FVector Origin{};
	FVector ActorBounds{};
	GetActorBounds(true, Origin, ActorBounds);
	FTransform ActorTransform{ GetActorTransform() };

	for (const auto& Actor : Actors)
		for (uint16 i{ 0 }; i < Count; ++i)
		{
			LocationOffset = FVector(0., 0., ActorBounds.Z / 4.);
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

