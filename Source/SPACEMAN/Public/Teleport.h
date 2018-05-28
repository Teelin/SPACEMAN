// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Teleport.generated.h"

class UBoxComponent;

UCLASS()
class SPACEMAN_API ATeleport : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATeleport();

	UPROPERTY(BlueprintReadOnly, Category = "Gameplay")
	TArray<AActor*> FoundActors;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		UStaticMeshComponent * TeleportMesh;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		UBoxComponent * BoxComp;

	virtual void NotifyActorBeginOverlap(AActor * OtherActor) override;

public:	
	

	
	
};
