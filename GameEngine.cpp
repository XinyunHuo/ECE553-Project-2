#include "GameEngine.h"
#include <iostream>
#include <fstream>

GameEngine::GameEngine() : field(nullptr), fieldHeight(0), fieldWidth(0), score(0), NUMBEROFVEGGIES(30), NUMBEROFRABBITS(5), captain(nullptr) {}

void GameEngine::initializeGame()
{
    initVeggies();
    initCaptain();
    initRabbits();
    score = 0;
}

void GameEngine::initVeggies()
{
    string fileName;
    cout << "Please enter the name of the vegetable point fiel: ";
    cin >> fileName;

    ifstream veggieFile(fileName);

    while (!veggieFile.is_open())
    {
        cout << fileName << " does not exist! Please enter the name of the vegetable point file: ";
        cin >> fileName;
        veggieFile.open(fileName);
    }

    //get height width

    field = new FieldInhabitant**[fieldHeight];
    for (int i = 0; i < fieldHeight; i++)
    {
        field[i] = new FieldInhabitant*[fieldWidth];
        for (int j = 0; j < fieldWidth; j++)
        {
            field[i][j] = nullptr;
        }
    }

    while (!veggieFile.eof())
    {
        string name;
        string symbol;
        int points;
        
        //get name symbol points

        Veggie* veggie = new Veggie(name, symbol, points);
        veggies.push_back(veggie);

        int x;
        int y;

        srand(time(0));

        do
        {
            x = rand() % fieldWidth;
            y = rand() % fieldHeight;
        } while (field[x][y] != nullptr);

        field[x][y] = veggie;
    }

    veggieFile.close();

}

void GameEngine::initCaptain()
{
    int x;
    int y;

    do
    {
        x = rand() % fieldWidth;
        y = rand() % fieldHeight;
    } while (field[x][y] != nullptr);

    captain = new Captain(x, y);
    field[x][y] = captain;
}

void GameEngine::initRabbits()
{
    for (int i = 0; i < 5; i++)
    {
        int x;
        int y;

        do
        {
            x = rand() % fieldWidth;
            y = rand() % fieldHeight;
        } while (field[x][y] != nullptr);

        Rabbit* rabbit = new Rabbit(x, y);
        rabbits.push_back(rabbit);
        field[x][y] = captain;
    }
}

int GameEngine::remainingVeggies() const
{
    int remainNum = 0;
    for (int i = 0; i < fieldWidth; i++)
    {
        for (int j = 0; j < fieldHeight; j++)
        {
            if (dynamic_cast<Veggie*>(field[i][j]) != nullptr)
            {
                remainNum++;
            }
        }
    }
    return remainNum;
}

void GameEngine::intro()
{
    cout << "Welcome to Captain Veggie!" << endl;
    cout << "The rabbits have invaded your garden and you must harvest" << endl;
    cout << "as many vegetables as possible before the rabbits eat them" << endl;
    cout << "all! Each vegetable is worth a different number of points" << endl;
    cout << "so go for the high score!" << endl;
}




