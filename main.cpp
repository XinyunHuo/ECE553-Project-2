#include "GameEngine.h"

using namespace std;

int main()
{
    GameEngine game;

    game.initializeGame();

    game.intro();

    int remainVeggie;
    remainVeggie = game.remainingVeggies();

    while (remainVeggie > 0)
    {
        cout << remainVeggie << " veggies remaining. Current score: " << game.getScore();

        game.printField();

        game.moveRabbits();

        game.moveCaptain();

        remainVeggie = game.remainingVeggies();
    }

    game.gameOver();

    cout << endl;
}