#include <iostream>
#include <string>
#include "Creature.h"
#include "Demon.h"

using std::string;
using std::cout;
using std::endl;

Demon::Demon() {
    strength = 0;
    hitpoints = 0;
}

Demon::Demon(int newStrength, int newHit) {
    strength = newStrength;
    hitpoints = newHit;
}

int Demon::getDamage() {
    cout << "[ERROR OCCURED]" << endl;
    return 0;
}

int Demon::inherentAbility(int damage) {

    if ((rand( ) % 100) < 5) {

        damage = damage + 50;
        cout << "Demonic attack inflicts 50 "
        << " additional damage points!" << endl;
            
    }

    return damage;

}

string Demon::getSpecies() {
    return "Demon";
}