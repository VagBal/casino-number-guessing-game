#include "../inc/Game/Game.h"

#include <ctime>
#include <random>
#include <limits>

int Game::generateRandom()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, difficultyLevel);
    return dis(gen);
}

void Game::askValue()
{
    int guess;
    std::cout << "Give me your guess" << "\n";
    while (!(std::cin >> guess)) {
        handleInvalidInput();
    }
    if (guess == this->num)
    {
        std::cout << "You guessed the number! Game over" << "\n";
        this->gameState = true;
    }
    else if(guess > this->num)
    {
        std::cout << "Your guess is bigger than the target number! Guess again" << "\n";
    }
    else
    {
        std::cout << "Your guess is lower than the target number! Guess again" << "\n";
    }
}

void Game::handleInvalidInput()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Invalid input. Please enter a number: ";
}

bool Game::getGameState()
{
    return this->gameState;
}

void Game::displayRules()
{
    std::cout << "Rules of the game:" << std::endl;
    std::cout << "1. Choose a difficulty level." << std::endl;
    std::cout << "2. Try to guess the number within the range." << std::endl;
    std::cout << "3. You will be prompted if your guess is too high or too low." << std::endl;
    std::cout << "4. Keep guessing until you find the correct number." << std::endl;
}

void Game::initializeGame()
{
    std::cout << "Hello! Give me your name: " << "\n";

    std::cin >> name;
    player.setName(name);

    std::cout << "Thank you, let's start the game " << player.getName() << "!" << "\n";
    std::cout << "Choose difficulty level (Easy : 0 - 10, Medium: 0 - 100, Hard: 0 - 1000)" << "\n";
    std::string level;
    std::cin >> level;

    if (level == "Easy") {
        difficultyLevel = Easy;
    } else if (level == "Medium") {
        difficultyLevel = Medium;
    } else if (level == "Hard") {
        difficultyLevel = Hard;
    } else {
        throw std::runtime_error("Invalid difficulty level");
    }

    std::cout << "Your choice is " << level << "!" << "\n";
    displayRules();
    num = generateRandom();
}

void Game::resetGame()
{
    gameState = false;
    name.clear();
    difficultyLevel = Easy; // or any default value
    num = 0;
}