#pragma once
#ifndef CAPTAIN_H
#define CAPTAIN_H

#include "Creature.h"
#include "Veggie.h"
#include <vector>

class Captain : public Creature {
private:
    vector<Veggie*> collectedVeggies;

public:
    // Constructor
    Captain(int xCoord, int yCoord);

    // Public function to add Veggie to the vector
    void addVeggie(Veggie* veggie);

    // Getter for collectedVeggies
    const vector<Veggie*>& getCollectedVeggies() const;

    // Setter for collectedVeggies (if needed)
    void setCollectedVeggies(const vector<Veggie*>& veggies);

    // Destructor
    ~Captain(); // Delete dynamically allocated Veggie objects
};

#endif // CAPTAIN_H

