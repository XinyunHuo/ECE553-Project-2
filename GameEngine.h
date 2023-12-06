#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "FieldInhabitant.h"
#include "Captain.h"
#include "Rabbit.h"

class GameEngine
{
    public:

        GameEngine();

        void initializeGame();
        void intro();
        void printField();
        void moveRabbits();
        void moveCaptain();
        void gameOver();

        int getScore() const;
        int remainingVeggies() const;

    private:

        FieldInhabitant*** field;
        int fieldHeight;
        int fieldWidth;
        int score;
        const int NUMBEROFVEGGIES;
        const int NUMBEROFRABBITS;

        Captain* captain;

        vector<Rabbit*> rabbits;
        vector<Veggie*> veggies;

        void initVeggies();
        void initCaptain();
        void initRabbits();
        void moveCptVertical(int movement);
        void moveCptHorizontal(int movement);

};

#endif