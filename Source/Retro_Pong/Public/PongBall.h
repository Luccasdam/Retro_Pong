// Copyright Luccas Machado. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PongBall.generated.h"

class USphereComponent;

UCLASS()
class RETRO_PONG_API APongBall : public AActor
{
	GENERATED_BODY()
	
public:	
	APongBall();
	virtual void PostInitializeComponents() override;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;


protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	TObjectPtr<USphereComponent> SphereCollisionComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	TObjectPtr<UStaticMeshComponent> BallMesh;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Properties")
	float Speed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Properties")
	float MaxAngle;

private:
	float Angle;
	float Direction;
	FVector MovementDirection;
};
