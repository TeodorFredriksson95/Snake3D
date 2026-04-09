// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "SnakeState.generated.h"

/**
 * 
 */


class ASnakeGameMode;
class USnakeGameInstance;


UCLASS()
class SNAKE3D_API ASnakeState : public APlayerState
{
	GENERATED_BODY()

public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnScoreUpdated, float, NewScore);

	UPROPERTY(BlueprintAssignable)
	FOnScoreUpdated OnScoreUpdated;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnReachedTargetScore);
	UPROPERTY(BlueprintAssignable)
	FOnReachedTargetScore OnReachedTargetScore;

protected:
	virtual void BeginPlay() override;

private:

	UFUNCTION(BlueprintCallable)
	void UpdateScore(const int32 SnakeID);

	TObjectPtr<USnakeGameInstance> GameInstance;
	TObjectPtr<ASnakeGameMode> SnakeGameMode;
};
