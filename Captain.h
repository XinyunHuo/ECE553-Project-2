/*
o A vector of Veggie pointers storing all of the Veggie objects the captain has collected
o A declaration for public constructor that takes in two integer parameters representing the x
	and y coordinates of the captain
o A declaration for a public function named addVeggie() that takes in pointer to a Veggie
object as a parameter, returns nothing, and adds the object to the vector of Veggie objects
o Declarations for appropriate getter/setter functions
o Appropriate header guards
*/

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

