#ifndef CYBERDEMON_H
#define CYBERDEMON_H

#include <iostream>
#include <string>
#include "Demon.h"

using std::string;
using std::cout;
using std::endl;

class Cyberdemon : public Demon{
public:
    Cyberdemon();
    Cyberdemon(int newStrength, int newHit);
    int getDamage();

private:
    string getSpecies(); // Returns type of species

};

#endif