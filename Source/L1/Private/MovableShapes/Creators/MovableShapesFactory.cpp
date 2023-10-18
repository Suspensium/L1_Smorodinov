// Fill out your copyright notice in the Description page of Project Settings.


#include "MovableShapesFactory.h"
#include <Kismet/GameplayStatics.h>

// Sets default values
AMovableShapesFactory::AMovableShapesFactory()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMovableShapesFactory::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMovableShapesFactory::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}