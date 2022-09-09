#ifndef DEMON_H
#define DEMON_H

#include <iostream>
#include <string>
#include "Creature.h"

using std::string;
using std::cout;
using std::endl;

class Demon : public Creature{
public:
    Demon();
    Demon(int newStrength, int newHit);
    int getDamage();

protected:
    int inherentAbility(int damage);
    string getSpecies(); // Returns type of species

};

#endif