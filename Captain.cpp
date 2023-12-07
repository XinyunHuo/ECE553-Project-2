#include "Captain.h"

// Constructor implementation
    // Call the superclass's constructor and pass the symbol "V" as well
Captain::Captain(int xCoord, int yCoord)
    : Creature(xCoord, yCoord, "V") {}

// Public function to add Veggie to the vector
void Captain::addVeggie(Veggie* veggie) {
    collectedVeggies.push_back(veggie);
}

// Getter implementation for collectedVeggies
const std::vector<Veggie*>& Captain::getCollectedVeggies() const {
    return collectedVeggies;
}

// Setter implementation for collectedVeggies (if needed)
void Captain::setCollectedVeggies(const std::vector<Veggie*>& veggies) {
    collectedVeggies = veggies;
}

// Destructor implementation
Captain::~Captain() {
    // Delete dynamically allocated Veggie objects in the collectedVeggies vector
    for (Veggie* veggie : collectedVeggies) {
        delete veggie;
    }
    collectedVeggies.clear();
}
