// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseMovableShape.h"
#include "Components/SphereComponent.h"

// Sets default values
ABaseMovableShape::ABaseMovableShape()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseMovableShape::BeginPlay()
{
	Super::BeginPlay();

	ColliderComponent = FindComponentByClass<USphereComponent>();
	if (ColliderComponent)
		ColliderComponent->OnComponentBeginOverlap.AddDynamic(this, &ABaseMovableShape::OnOverlapBegin);
}

void ABaseMovableShape::HandleMovement(float DeltaTime)
{
	if (!EndPoint) return;
	if (!ColliderComponent) return;

	// Calculate the direction to the EndPoint
	FVector Direction = EndPoint->GetActorLocation() - GetActorLocation();
	Direction.Normalize();

	Move(Direction, DeltaTime);
}

void ABaseMovableShape::Move(FVector Direction, float DeltaTime)
{
	// Apply force to mesh to move it
	ColliderComponent->AddForce(MovementSpeed * 10000.f * Direction * DeltaTime);
}

void ABaseMovableShape::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor == EndPoint)
		Destroy();
}

// Called every frame
void ABaseMovableShape::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

