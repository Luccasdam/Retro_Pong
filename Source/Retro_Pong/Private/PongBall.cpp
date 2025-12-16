// Copyright Luccas Machado. All rights reserved.


#include "PongBall.h"

#include "Components/SphereComponent.h"


APongBall::APongBall()
{
	PrimaryActorTick.bCanEverTick = true;

	Speed = 600.f;
	MaxAngle = 60.f;
	Direction = 1;
	MovementDirection = FVector::ZeroVector;

	SphereCollisionComponent = CreateDefaultSubobject<USphereComponent>("SphereCollisionComponent");
	SetRootComponent(SphereCollisionComponent);

	BallMesh = CreateDefaultSubobject<UStaticMeshComponent>("BallMesh");
	BallMesh->SetupAttachment(SphereCollisionComponent);
}

void APongBall::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	
}


void APongBall::BeginPlay()
{
	Super::BeginPlay();

	Angle = FMath::RandRange(-MaxAngle, MaxAngle);
	Direction = FMath::RandBool() ? 1.f : -1.f;

	const float MoveUp = FMath::Sin(FMath::DegreesToRadians(Angle));
	const float MoveRight = FMath::Cos(FMath::DegreesToRadians(Angle)) * Direction;
	
	FString DebugMsg = FString::Printf(TEXT("Cos 60 = %f"), FMath::Cos(FMath::DegreesToRadians(60.f)));
	GEngine->AddOnScreenDebugMessage(1, 30.f, FColor::White, DebugMsg);
	
	MovementDirection = FVector(0.f, MoveRight, MoveUp).GetSafeNormal();
}


void APongBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FHitResult Hit;
	AddActorWorldOffset(MovementDirection * Speed * DeltaTime, true, &Hit);

	if (IsValid(Hit.GetActor()))
	{
		const FVector BounceDirection = MovementDirection - 2 * (FVector::DotProduct(MovementDirection.GetSafeNormal(), Hit.ImpactNormal) * Hit.ImpactNormal);
		MovementDirection = BounceDirection.GetSafeNormal();
	}
}

