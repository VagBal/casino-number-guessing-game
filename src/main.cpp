#include "../inc/Game/Game.h"

int main()
{
    std::cout << "Welcome to the Casino Number Guessing Game!" << std::endl;

    Game game;
    game.initializeGame();

    while (true)
    {
        if (game.getGameState()) {
            char choice;
            std::cout << "Do you want to play again? (y/n): ";
            std::cin >> choice;
            if (choice == 'y' || choice == 'Y') {
                game.resetGame();
                game.initializeGame();
            } else {
                break;
            }
        } else {
            game.askValue();
        }
    }
    
    return 0;
}