#ifndef ELF_H
#define ELF_H

#include <iostream>
#include <string>
#include "Creature.h"

using std::string;
using std::cout;
using std::endl;

class Elf : public Creature{
public:
    Elf();
    Elf(int newStrength, int newHit);
    int getDamage();

private:
    string getSpecies(); // Returns type of species

};

#endif