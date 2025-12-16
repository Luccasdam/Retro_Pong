// Copyright Luccas Machado. All rights reserved.


#include "PongPaddle.h"
#include "Components/BoxComponent.h"


APongPaddle::APongPaddle()
{
	PrimaryActorTick.bCanEverTick = false;

	BoxCollisionComponent = CreateDefaultSubobject<UBoxComponent>("BoxCollisionComponent");
	SetRootComponent(BoxCollisionComponent);

	PaddleMesh = CreateDefaultSubobject<UStaticMeshComponent>("PaddleMesh");
	PaddleMesh->SetupAttachment(BoxCollisionComponent);
}


void APongPaddle::BeginPlay()
{
	Super::BeginPlay();
}
