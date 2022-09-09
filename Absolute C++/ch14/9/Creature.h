#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Creature {
public:
    Creature();
    Creature(int newStrength, int newHit);
    int getDamage();

protected:
    int strength; // How much damage we can inflict
    int hitpoints; // How much damage we can sustain
    string getSpecies(); // Returns type of species

};

#endif