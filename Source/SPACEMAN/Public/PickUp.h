// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickUp.generated.h"


class USphereComponent;

UCLASS()
class SPACEMAN_API APickUp : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickUp();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		UStaticMeshComponent * PickupMesh;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		USphereComponent * SphereComp;

	virtual void NotifyActorBeginOverlap(AActor * OtherActor) override;

public:	
	

	
	
};
