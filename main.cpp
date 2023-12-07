#include "GameEngine.h"

using namespace std;

int main()
{
    GameEngine game;

    game.initializeGame(); // initialize game

    game.intro(); //print game intro

    int remainVeggie;
    remainVeggie = game.remainingVeggies(); //get remain vegetable number

    while (remainVeggie > 0) //update game
    {
        cout << remainVeggie << " veggies remaining. Current score: " << game.getScore() << endl;

        game.printField();

        game.moveRabbits();

        //bonus part
        game.moveSnake();
        //bonus part end

        game.moveCaptain();

        cout << endl;

        remainVeggie = game.remainingVeggies();
    }

    game.gameOver(); //game over

    cout << endl;

    return 0;
}