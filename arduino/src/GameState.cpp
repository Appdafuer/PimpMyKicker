#include "GameState.h"

GameState::GameState()
{
    this->goals1 = 0;
    this->goals2 = 0;

    byte noAdress[4] = {0x00, 0x00, 0x00, 0x00};

    memcpy(this->playerId1, noAdress, 4);
    memcpy(this->playerId2, noAdress, 4);
    memcpy(this->playerId3, noAdress, 4);
    memcpy(this->playerId4, noAdress, 4);
}

void GameState::startNewGame()
{
    //update result to firebase

    //setting players available to false
    byte noAdress[4] = {0x00, 0x00, 0x00, 0x00};

    memcpy(this->playerId1, noAdress, 4);
    memcpy(this->playerId2, noAdress, 4);
    memcpy(this->playerId3, noAdress, 4);
    memcpy(this->playerId4, noAdress, 4);

    this->gameFinished = false;

    this->goals1 = 0;
    this->goals2 = 0;
}
