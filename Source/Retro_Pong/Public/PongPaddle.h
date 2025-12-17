// Copyright Luccas Machado. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "PongPaddleMovementComponent.h"
#include "GameFramework/Pawn.h"
#include "PongStatics.h"
#include "PongPaddle.generated.h"

class UBoxComponent;
class UPongPaddleMovementComponent;

UCLASS()
class RETRO_PONG_API APongPaddle : public APawn
{
	GENERATED_BODY()

public:
	APongPaddle();

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void AddPaddleMovementInput(EMovementDirection MovementDirection);


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	TObjectPtr<UBoxComponent> BoxCollisionComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	TObjectPtr<UStaticMeshComponent> PaddleMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	TObjectPtr<UPongPaddleMovementComponent> PaddleMovementComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Defaults")
	EPlayer Player = EPlayer::One;
};
