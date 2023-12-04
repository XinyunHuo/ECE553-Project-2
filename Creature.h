/*
o Define the constructor so it stores the parameter values in the appropriate member variables
    ~ The superclass¡¯s constructor should be called and the symbol should be passed to it
o Define the getter/setter functions

*/

#pragma once
#ifndef CREATURE_H
#define CREATURE_H

#include "FieldInhabitant.h"

class Creature : public FieldInhabitant {
private:
    int xCoordinate;
    int yCoordinate;

public:
    // Constructor
    Creature(int xCoord, int yCoord, const string& symbol);

    // Getter for x-coordinate
    int getXCoordinate() const;

    // Setter for x-coordinate
    void setXCoordinate(int newX);

    // Getter for y-coordinate
    int getYCoordinate() const;

    // Setter for y-coordinate
    void setYCoordinate(int newY);
};

#endif // CREATURE_H

