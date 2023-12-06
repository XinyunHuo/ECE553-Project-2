/*
o Define the constructor so it stores the parameter values in the appropriate member variables
    ~ The superclass��s constructor should be called and the symbol should be passed to it
o Define the getter/setter functions
*/

#include "Veggie.h"

// Constructor implementation
    // Call the superclass's constructor and pass the symbol to it
    // Store the parameter values in the member variables
Veggie::Veggie(const string& vegetableName, const string& symbol, int pointValue)
    : FieldInhabitant(symbol), vegetableName(vegetableName), pointValue(pointValue) {}

// Getter implementations
string Veggie::getVegetableName() const {
    return vegetableName;
}

int Veggie::getPointValue() const {
    return pointValue;
}

// Setter implementations
void Veggie::setVegetableName(const string& newName) {
    vegetableName = newName;
}

void Veggie::setPointValue(int newValue) {
    pointValue = newValue;
}
