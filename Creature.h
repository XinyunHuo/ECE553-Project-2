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

