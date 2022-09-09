#ifndef HUMAN_H
#define HUMAN_H

#include <iostream>
#include <string>
#include "Creature.h"

using std::string;
using std::cout;
using std::endl;

class Human : public Creature{
public:
    Human();
    Human(int newStrength, int newHit);
    int getDamage();

private:
    string getSpecies(); // Returns type of species

};

#endif