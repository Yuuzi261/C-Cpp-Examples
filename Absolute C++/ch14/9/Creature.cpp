#include <iostream>
#include <string>
#include "Creature.h"

using std::string;
using std::cout;
using std::endl;

Creature::Creature() {
    strength = 0;
    hitpoints = 0;
}

Creature::Creature(int newStrength, int newHit) {
    strength = newStrength;
    hitpoints = newHit;
}

int Creature::getDamage() {
    cout << "[ERROR OCCURED]" << endl;
    return 0;
}

string Creature::getSpecies() {
    return "Unknown";
}