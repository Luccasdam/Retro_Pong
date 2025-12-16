// Copyright Luccas Machado. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PongPaddle.generated.h"

class UBoxComponent;


UENUM(BlueprintType)
enum class EPlayer : uint8
{
	One,
	Two
};

UCLASS()
class RETRO_PONG_API APongPaddle : public APawn
{
	GENERATED_BODY()

public:
	APongPaddle();

protected:
	virtual void BeginPlay() override;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	TObjectPtr<UBoxComponent> BoxCollisionComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	TObjectPtr<UStaticMeshComponent> PaddleMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Defaults")
	EPlayer Player = EPlayer::One;
};
