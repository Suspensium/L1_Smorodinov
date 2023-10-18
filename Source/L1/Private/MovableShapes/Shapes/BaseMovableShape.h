// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectPtr.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "BaseMovableShape.generated.h"

UCLASS(Abstract)
class ABaseMovableShape : public AActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category = "Movement")
	float MovementSpeed{ 100.f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	// Actor's movement end point
	TObjectPtr<AActor> EndPoint;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "Movement")
	bool bMoving{ true };

	TObjectPtr<USphereComponent> ColliderComponent{ nullptr };

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Movement")
	// Called to move towards EndPoint
	virtual void HandleMovement(float DeltaTime);

	virtual void Move(const FVector& Direction, float DeltaTime) PURE_VIRTUAL(ABaseMovableShape::Move, );

	UFUNCTION()
	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
public:
	// Sets default values for this actor's properties
	ABaseMovableShape();

	void SetEndPoint(TObjectPtr<AActor> p_EndPoint);

	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
