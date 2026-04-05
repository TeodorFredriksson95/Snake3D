// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "FoodSpawner.generated.h"

UCLASS()
class SNAKE3D_API AFoodSpawner : public AActor
{
	GENERATED_BODY()

public:
	AFoodSpawner();
	void virtual Tick(float DeltaSeconds) override;	

	
protected:
	virtual void BeginPlay() override;

private:
		
	TObjectPtr<UBoxComponent> SpawnBox;

	UPROPERTY(EditAnywhere, Category="Spawning")
	TSubclassOf<AActor> ActorToSpawn;

	UPROPERTY(EditAnywhere, Category="Spawning")
	float SpawnsMultiplier = 1;
	
	UPROPERTY(EditAnywhere, Category="Spawning")
	int32 InitialSpawnAmount = 15;
	
	UPROPERTY(EditAnywhere, Category="Spawning Timer")
	float SpawnCooldown = 5;
	
	float SpawnCooldownCounter = 0;
	
	void SpawnFood() const;
};
