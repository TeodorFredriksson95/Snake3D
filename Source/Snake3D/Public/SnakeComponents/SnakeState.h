// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "SnakeState.generated.h"

/**
 * 
 */


class USnakeGameInstance;

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
	void SetSnakeScore(int32 SnakeID, float NewScore);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnScoreUpdated, float, NewScore);
	UPROPERTY(BlueprintAssignable)
	FOnScoreUpdated OnScoreUpdated; 
	
protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION(BlueprintCallable)
	void SetPlayerStateScore(const float NewScore)
	{
		SetScore(NewScore);
	}

	ESnakeGameLevel CurrentLevel = ESnakeGameLevel::FirstLevel;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnReachedTargetScore, ESnakeGameLevel, CurrentLevel);

	UPROPERTY(BlueprintAssignable)
	FOnReachedTargetScore OnReachedTargetScore;

	TObjectPtr<USnakeGameInstance> GameInstance;
	
	UFUNCTION(BlueprintCallable)
	void UpdateScore(const int32 SnakeID);

};
