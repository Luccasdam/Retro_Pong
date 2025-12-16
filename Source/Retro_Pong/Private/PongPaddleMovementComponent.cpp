// Copyright Luccas Machado. All rights reserved.


#include "PongPaddleMovementComponent.h"
#include "PongPaddle.h"
#include "Kismet/GameplayStatics.h"


UPongPaddleMovementComponent::UPongPaddleMovementComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}


void UPongPaddleMovementComponent::AddMovementInput(EMovementDirection MovementDirection) const
{
	float DeltaSeconds = UGameplayStatics::GetWorldDeltaSeconds(this);
	APongPaddle* OwningPaddle = Cast<APongPaddle>(GetOwner());

	if (!IsValid(OwningPaddle))
	{
		return;
	}
	
	switch (MovementDirection)
	{
		case EMovementDirection::Up:
			OwningPaddle->AddActorWorldOffset(FVector::UpVector * MovementSpeed * DeltaSeconds, true);
			break;
		case EMovementDirection::Down:
			OwningPaddle->AddActorWorldOffset(-FVector::UpVector * MovementSpeed * DeltaSeconds, true);
			break;
	}
}
