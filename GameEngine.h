#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "FieldInhabitant.h"
#include "Captain.h"
#include "Rabbit.h"
#include <iostream>

class GameEngine
{
    public:

        GameEngine();

        // @brief This function is to initialize the game
        void initializeGame();

        // @brief Thsi function is to output game intro
        void intro();

        // @brief Thsi function is to print field
        void printField();

        // @brief Thsi function is to move rabbit position
        void moveRabbits();

        // @brief this function is to move captain base on user input
        void moveCaptain();

        // @brief this function indicate the end of game
        void gameOver();

        // @brief Thsi function is to get the player score
        int getScore() const;

        // @brief Thsi function is to get number of remaining vegetable
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

        // @brief This function is to initialize vegetable in the game
        void initVeggies();

        // @brief Thsi function is to initialize captain position
        void initCaptain();

        // @brief Thsi function is to initialize rabbit position
        void initRabbits();

        // @brief Thsi function is to move captain position vertical
        // @param movement indicate the direction and length of movement
        void moveCptVertical(int movement);

        // @brief Thsi function is to move captain position horizontal
        // @param movement indicate the direction and length of movement
        void moveCptHorizontal(int movement);

};

#endif