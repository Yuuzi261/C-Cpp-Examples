#include <iostream>
#include <string>
#include "Creature.h"
#include "Elf.h"

using std::string;
using std::cout;
using std::endl;

Elf::Elf() {
    strength = 10;
    hitpoints = 10;
}

Elf::Elf(int newStrength, int newHit) {
    strength = newStrength;
    hitpoints = newHit;
}

int Elf::getDamage() {

    int damage;

    damage = (rand() % strength) + 1;
    cout << getSpecies( ) << " attacks for " << damage << " points!" << endl;

    if ((rand( ) % 10)==0) {
        cout << "Magical attack inflicts " << damage << " additional damage points!" << endl;
        damage = damage * 2;
    }

    return damage;

}

string Elf::getSpecies() {
    return "Elf";
}