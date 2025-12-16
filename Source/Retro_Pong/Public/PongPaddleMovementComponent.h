// Copyright Luccas Machado. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PongPaddleMovementComponent.generated.h"


UENUM(BlueprintType)
enum class  EMovementDirection : uint8
{
	Up,
	Down
};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RETRO_PONG_API UPongPaddleMovementComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UPongPaddleMovementComponent();
	void AddMovementInput(EMovementDirection MovementDirection) const;


protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Defaults")
	float MovementSpeed = 100.f;
};
