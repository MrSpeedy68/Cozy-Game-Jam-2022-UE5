// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickups.h"

// Sets default values
APickups::APickups()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Collision = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
	Collision->SetupAttachment(RootComponent);

	Collision->SetSphereRadius(50.0);
}

// Called when the game starts or when spawned
void APickups::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APickups::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

