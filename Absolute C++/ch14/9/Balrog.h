#ifndef BALROG_H
#define BALROG_H

#include <iostream>
#include <string>
#include "Demon.h"

using std::string;
using std::cout;
using std::endl;

class Balrog : public Demon{
public:
    Balrog();
    Balrog(int newStrength, int newHit);
    int getDamage();

private:
    string getSpecies(); // Returns type of species

};

#endif