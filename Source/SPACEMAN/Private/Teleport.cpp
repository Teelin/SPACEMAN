// Fill out your copyright notice in the Description page of Project Settings.

#include "Teleport.h"
#include "Components/BoxComponent.h"
#include "SPACEMANCharacter.h"
#include <EngineGlobals.h>
#include <Runtime/Engine/Classes/Engine/Engine.h>
#include "EngineUtils.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ATeleport::ATeleport()
{

	TeleportMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TeleportMesh"));
	TeleportMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RootComponent = TeleportMesh;


	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	BoxComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	BoxComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	BoxComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	BoxComp->SetupAttachment(TeleportMesh);


}

// Called when the game starts or when spawned
void ATeleport::BeginPlay()
{
	Super::BeginPlay();
	
}


void ATeleport::NotifyActorBeginOverlap(AActor * OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);



	ASPACEMANCharacter* MyCharacter = Cast<ASPACEMANCharacter>(OtherActor);

	if (MyCharacter)
	{
		MyCharacter->bInTeleport = true;
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("Beam Me Up"));
		

		
		UGameplayStatics::GetAllActorsOfClass(MyCharacter->GetWorld(), ATeleport::StaticClass(), FoundActors);
	}
}
