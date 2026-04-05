// Fill out your copyright notice in the Description page of Project Settings.


#include "SnakeComponents/SnakeGameMode.h"

#include "SnakeComponents/SnakeGameInstance.h"

void ASnakeGameMode::SetGameState(ESnakeGameState NewState)
{
	CurrentState = NewState;
	UE_LOG(LogTemp, Warning, TEXT("GameState changed to %d"), (int32)NewState);
	OnGameStateChanged.Broadcast(NewState);
}

void ASnakeGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	if (!NewPlayer) return;

	ULocalPlayer* LocalPlayer = NewPlayer->GetLocalPlayer();
	if (!LocalPlayer) return;

	int32 PlayerIndex = LocalPlayer->GetControllerId();

	USnakeGameInstance* SnakeGameInstance = GetGameInstance<USnakeGameInstance>();
	if (SnakeGameInstance)
	{
		SnakeGameInstance->AddPlayerToDataMap(PlayerIndex);
	}
}

void ASnakeGameMode::BeginPlay()
{
	Super::BeginPlay();
	
	SetGameState(ESnakeGameState::MainMenu);
}
