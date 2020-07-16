#include "GameManager.h"

GameManager::GameManager(){};

void GameManager::setup(InputState *inputState, GameState *gameState)
{
    this->inputState = inputState;
    this->gameState = gameState;
};

void GameManager::update()
{
    if (inputState->nfcId1 != 0x00)
    {
        gameState->player1Available = true;
    }
    if (inputState->nfcId2 != 0x00)
    {
        gameState->player2Available = true;
    }
    if (inputState->nfcId3 != 0x00)
    {
        gameState->player3Available = true;
    }
    if (inputState->nfcId4 != 0x00)
    {
        gameState->player4Available = true;
    }

    if (inputState->leftButtonPressed == true)
    {
        if (gameState->gameFinished == true)
        {
            gameState->startNewGame();
        }
        else
        {
            gameState->goals1++;
        }
    }

    if (inputState->rightButtonPressed == true)
    {
        if (gameState->gameFinished == true)
        {
            gameState->startNewGame();
        }
        else
        {
            gameState->goals2++;
        }
    }

    //check if game is finished
    if (gameState->goals1 >= 6 || gameState->goals2 >= 6)
    {
        gameState->gameFinished = true;
    }
};