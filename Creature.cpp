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
