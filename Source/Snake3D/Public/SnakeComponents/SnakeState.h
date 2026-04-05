// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "SnakeState.generated.h"

/**
 * 
 */

	
UENUM(BlueprintType)
enum class ESnakeGameLevel : uint8
{
	FirstLevel,
	SecondLevel,
	ThirdLevel
};

UCLASS()
class SNAKE3D_API ASnakeState : public APlayerState
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void SetSnakeScore(float NewScore);
	
private:
	ESnakeGameLevel CurrentLevel = ESnakeGameLevel::FirstLevel;
	
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnReachedTargetScore, ESnakeGameLevel, CurrentLevel);


	UPROPERTY(BlueprintAssignable)
	FOnReachedTargetScore OnReachedTargetScore;
};
