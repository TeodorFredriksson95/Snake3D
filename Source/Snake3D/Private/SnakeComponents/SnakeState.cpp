// Fill out your copyright notice in the Description page of Project Settings.


#include "SnakeComponents/SnakeState.h"


void ASnakeState::SetSnakeScore(const float NewScore)
{
	SetScore(NewScore);
	
	if (GetScore() == 5 && CurrentLevel == ESnakeGameLevel::FirstLevel)
	{
		CurrentLevel = ESnakeGameLevel::SecondLevel;
		OnReachedTargetScore.Broadcast(CurrentLevel);
	}
	else if (GetScore() == 10 && CurrentLevel == ESnakeGameLevel::SecondLevel)
	{
		CurrentLevel = ESnakeGameLevel::ThirdLevel;
		OnReachedTargetScore.Broadcast(CurrentLevel);
	}
	else if (GetScore() == 15 && CurrentLevel == ESnakeGameLevel::ThirdLevel)
	{
		OnReachedTargetScore.Broadcast(CurrentLevel);
	}
	
}
