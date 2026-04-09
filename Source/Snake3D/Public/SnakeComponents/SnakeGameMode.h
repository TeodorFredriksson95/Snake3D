// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SnakeGameMode.generated.h"

enum class ESnakeGameLevel: uint8;
/**
 * 
 */
UENUM(BlueprintType)
enum class ESnakeGameState : uint8
{
	MainMenu,
	Game,
	Outro
};


UCLASS()
class SNAKE3D_API ASnakeGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	void virtual PostLogin(APlayerController* NewPlayer) override;
	
	UFUNCTION()
	void HandleReachedTargetScore();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category="Level Management")
	TArray<FName> LevelNames;
};
