// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SnakeTail.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGameOver, int32, SnakePlayerScore, int32, SnakePlayerID);

UCLASS()
class SNAKE3D_API ASnakeTail : public AActor
{
	GENERATED_BODY()

public:
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	UPROPERTY(BlueprintAssignable)
	FOnGameOver OnGameOver;

protected:
	virtual void BeginPlay() override;

private:
};
