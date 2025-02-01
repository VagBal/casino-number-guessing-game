#ifndef GAME_H
#define GAME_H

#include <cstdlib>
#include <iostream>
#include <map>
#include "../Player/Player.h"

class Game
{
public:
    enum DifficultyLevel {
        Easy = 10,
        Medium = 100,
        Hard = 1000
    };

    Game() : player(), gameState(false) {}

    void initializeGame();
    int generateRandom();
    void askValue();
    bool getGameState();
    void handleInvalidInput();
    void displayRules();
    void resetGame();

private:
    Player player;
    std::string name;
    DifficultyLevel difficultyLevel;
    bool gameState;

    int num;
};

#endif