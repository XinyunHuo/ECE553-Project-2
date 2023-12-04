/*
o Define the constructor so it stores the parameter value in the appropriate member variable
o Define the getter/setter functions
o Define the deconstructor so that is does nothing
*/

#include "FieldInhabitant.h"

// Constructor implementation
FieldInhabitant::FieldInhabitant(const string& symbol) : symbol(symbol) {}

// Getter implementation
string FieldInhabitant::getSymbol() const {
    return symbol;
}

// Setter implementation
void FieldInhabitant::setSymbol(const string& newSymbol) {
    symbol = newSymbol;
}

// Destructor implementation (does nothing)
FieldInhabitant::~FieldInhabitant() {}
