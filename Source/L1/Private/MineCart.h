// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MineCart.generated.h"

UCLASS()
class AMineCart : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditInstanceOnly)
	// Is filled with coal
	bool bFilled{ false };

	UFUNCTION(BlueprintCallable)
	// Fill a cart with actors from set
	void FillCartWithActors(const TSet<TSubclassOf<AActor>>& Actors, int Count = 10);

public:
	// Sets default values for this actor's properties
	AMineCart();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
