#include "GameState.h"

GameState::GameState()
{
    this->goals1 = 0;
    this->goals2 = 0;

    // TODO: create array
    this->player1Available = false;
    this->player2Available = false;
    this->player3Available = false;
    this->player4Available = false;
}

void GameState::startNewGame()
{
    //update result to firebase

    //setting players available to false
    this->player1Available = false;
    this->player2Available = false;
    this->player3Available = false;
    this->player4Available = false;

    this->gameFinished = false;

    this->goals1 = 0;
    this->goals2 = 0;
}
