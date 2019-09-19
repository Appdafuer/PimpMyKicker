#include "GameManager.h"

GameManager::GameManager(){};

void GameManager::setup(InputState inputState, GameState gameState)
{
    this->inputState = inputState;
    this->gameState = gameState;
};

void GameManager::update()
{
    if (inputState.nfcId1 != 0x00)
    {
        gameState.player1Available = true;
    }
    if (inputState.nfcId2 != 0x00)
    {
        gameState.player2Available = true;
    }
    if (inputState.nfcId3 != 0x00)
    {
        gameState.player3Available = true;
    }
    if (inputState.nfcId4 != 0x00)
    {
        gameState.player4Available = true;
    }
};