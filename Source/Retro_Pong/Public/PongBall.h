// Copyright Luccas Machado. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "PongStatics.h"
#include "GameFramework/Actor.h"
#include "PongBall.generated.h"

class USphereComponent;

UCLASS(Abstract)
class RETRO_PONG_API APongBall : public AActor
{
	GENERATED_BODY()
	
public:	
	APongBall();
	virtual void PostInitializeComponents() override;

	UFUNCTION(BlueprintCallable)
	virtual void Reset() override;
	
	UFUNCTION(BlueprintCallable)
	void Launch();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void UpdateColor(FLinearColor InColor);

	UFUNCTION(BlueprintCallable)
	void UpdateForceDirection(int32 NewDirection);


protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	TObjectPtr<USphereComponent> SphereCollisionComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	TObjectPtr<UStaticMeshComponent> BallMesh;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Properties")
	float Speed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Properties")
	float SpeedIncrease;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Properties")
	float MaxAngle;

	UPROPERTY(BlueprintReadWrite, Category="Properties")
	TObjectPtr<UMaterialInstanceDynamic> DynamicMaterialInstance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Properties")
	TObjectPtr<USoundBase> PaddleHitSFX;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Properties")
	TObjectPtr<USoundBase> WallHitSFX;

private:
	float Angle;
	float Direction;
	float CurrentSpeed;
	FVector MovementDirection;
	int8 ForceDirection;
};
