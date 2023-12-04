/*
o A string member variable to store the name of the vegetable
o An integer member variable to store the point value of the vegetable
o A declaration for public constructor that takes in two string parameters representing the name
    and symbol of the vegetable and an integer representing the number of points the vegetable is
    worth
o Declarations for appropriate getter/setter functions
o Appropriate header guards
*/
#pragma once
#ifndef VEGGIE_H
#define VEGGIE_H

#include "FieldInhabitant.h"

class Veggie : public FieldInhabitant {
private:
    string vegetableName;
    int pointValue;

public:
    // Constructor
    Veggie(const string& vegetableName, const string& symbol, int pointValue);

    // Getter for vegetable name
    string getVegetableName() const;

    // Setter for vegetable name
    void setVegetableName(const string& newName);

    // Getter for point value
    int getPointValue() const;

    // Setter for point value
    void setPointValue(int newValue);
};

#endif // VEGGIE_H

