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

