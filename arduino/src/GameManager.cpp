#include "GameManager.h"

GameManager::GameManager(){};

void GameManager::setup(InputState *inputState, GameState *gameState, OutputState *outputState)
{
    this->inputState = inputState;
    this->gameState = gameState;
    this->outputState = outputState;
};

void GameManager::update()
{
    // TODO: Export to function
    // TODO: Check if inputState is noAddress --> DO NOT PEEP
    if ((inputState->nfcId1[0] == gameState->playerId1[0] &&
         inputState->nfcId1[1] == gameState->playerId1[1] &&
         inputState->nfcId1[2] == gameState->playerId1[2] &&
         inputState->nfcId1[3] == gameState->playerId1[3]) == false)
    {
        memcpy(gameState->playerId1, inputState->nfcId1, 4);
        outputState->peep = true;
    }

    if ((inputState->nfcId2[0] == gameState->playerId2[0] &&
         inputState->nfcId2[1] == gameState->playerId2[1] &&
         inputState->nfcId2[2] == gameState->playerId2[2] &&
         inputState->nfcId2[3] == gameState->playerId2[3]) == false)
    {
        memcpy(gameState->playerId2, inputState->nfcId2, 4);
        outputState->peep = true;
    }

    if ((inputState->nfcId3[0] == gameState->playerId3[0] &&
         inputState->nfcId3[1] == gameState->playerId3[1] &&
         inputState->nfcId3[2] == gameState->playerId3[2] &&
         inputState->nfcId3[3] == gameState->playerId3[3]) == false)
    {
        memcpy(gameState->playerId3, inputState->nfcId3, 4);
        outputState->peep = true;
    }

    if ((inputState->nfcId4[0] == gameState->playerId4[0] &&
         inputState->nfcId4[1] == gameState->playerId4[1] &&
         inputState->nfcId4[2] == gameState->playerId4[2] &&
         inputState->nfcId4[3] == gameState->playerId4[3]) == false)
    {
        memcpy(gameState->playerId4, inputState->nfcId4, 4);
        outputState->peep = true;
    }

    if (inputState->leftButtonPressed == true)
    {
        if (gameState->gameFinished == true)
        {
            gameState->startNewGame();
            outputState->peep = true;
        }
        else
        {
            gameState->goals1++;
            Serial.println(gameState->goals1);
        }
    }

    if (inputState->rightButtonPressed == true)
    {
        if (gameState->gameFinished == true)
        {
            gameState->startNewGame();
            outputState->peep = true;
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