// Fill out your copyright notice in the Description page of Project Settings.


#include "SnakeComponents/SnakeTail.h"

#include "GameFramework/PlayerState.h"
#include "SnakeComponents/SnakeCharacter.h"
#include "SnakeComponents/SnakeController.h"
#include "SnakeComponents/SnakeGameInstance.h"


void ASnakeTail::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	const ASnakeCharacter* SnakeCharacter = Cast<ASnakeCharacter>(OtherActor);
	if (!SnakeCharacter) return;

	ASnakeController* SnakeController = Cast<ASnakeController>(SnakeCharacter->GetController());
	if (!SnakeController) return;

	USnakeGameInstance* GameInstance = GetGameInstance<USnakeGameInstance>();
	if (!GameInstance) return;

	const int32 SnakePlayerID = SnakeController->GetLocalPlayer()->GetControllerId();
	const int WinnerIndex = (SnakePlayerID == 0) ? 1 : 0;

	const FPlayerPersistentData PlayerData = GameInstance->GetSnakePlayerData(WinnerIndex);

	SnakeController->ShowOutro(WinnerIndex + 1, PlayerData.Score );
}

void ASnakeTail::BeginPlay()
{
	Super::BeginPlay();
}
