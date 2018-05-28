// Fill out your copyright notice in the Description page of Project Settings.

#include "PickUp.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "SPACEMANCharacter.h"
#include <EngineGlobals.h>
#include <Runtime/Engine/Classes/Engine/Engine.h>



// Sets default values
APickUp::APickUp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	
	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));
	PickupMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RootComponent = PickupMesh;

	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("ShereComp"));
	SphereComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	SphereComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	SphereComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	SphereComp->SetupAttachment(PickupMesh);

	
}

// Called when the game starts or when spawned
void APickUp::BeginPlay()
{
	Super::BeginPlay();
	
}

void APickUp::NotifyActorBeginOverlap(AActor * OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	

	ASPACEMANCharacter* MyCharacter = Cast<ASPACEMANCharacter>(OtherActor);

	if (MyCharacter)
	{
		//MyCharacter->bGotObjective = true;
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("Object Picked Up!"));
		Destroy();
	}
}

