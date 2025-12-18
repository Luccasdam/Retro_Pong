// Copyright Luccas Machado. All rights reserved.


#include "PongBall.h"

#include "PongPaddle.h"
#include "Components/SphereComponent.h"


APongBall::APongBall()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = false;

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

void APongBall::Reset()
{
	Super::Reset();

	TeleportTo(FVector::ZeroVector, FRotator::ZeroRotator);
	PrimaryActorTick.SetTickFunctionEnable(false);
}

void APongBall::Launch()
{
	Angle = FMath::RandRange(-MaxAngle, MaxAngle);
	Direction = FMath::RandBool() ? 1.f : -1.f;

	const float MoveUp = FMath::Sin(FMath::DegreesToRadians(Angle));
	const float MoveRight = FMath::Cos(FMath::DegreesToRadians(Angle)) * Direction;
	
	MovementDirection = FVector(0.f, MoveRight, MoveUp).GetSafeNormal();
	
	PrimaryActorTick.SetTickFunctionEnable(true);
}


void APongBall::BeginPlay()
{
	Super::BeginPlay();
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

		if (APongPaddle* PongPaddle = Cast<APongPaddle>(Hit.GetActor()))
		{
			LastHitPlayer = PongPaddle->GetPlayer();
			UpdateColor(PongPaddle->GetColor());
		}
	}
}

void APongBall::UpdateColor(FLinearColor InColor)
{
	if (DynamicMaterialInstance)
	{
		DynamicMaterialInstance->SetVectorParameterValue("Color", InColor);
	}
}

