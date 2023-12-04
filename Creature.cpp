/*
o Two integer member variables to store the x and y coordinates of the creature
o A declaration for public constructor that takes in two integer parameters representing the x
    and y coordinates of the creature and a string representing the symbol of the creature
o Declarations for appropriate getter/setter functions
o Appropriate header guards
*/

#include "Creature.h"

// Constructor implementation
    // Call the superclass's constructor and pass the symbol to it
    // Store the parameter values in the member variables
Creature::Creature(int xCoord, int yCoord, const string& symbol)
    : FieldInhabitant(symbol), xCoordinate(xCoord), yCoordinate(yCoord) {}

// Getter implementations
int Creature::getXCoordinate() const {
    return xCoordinate;
}

int Creature::getYCoordinate() const {
    return yCoordinate;
}

// Setter implementations
void Creature::setXCoordinate(int newX) {
    xCoordinate = newX;
}

void Creature::setYCoordinate(int newY) {
    yCoordinate = newY;
}
