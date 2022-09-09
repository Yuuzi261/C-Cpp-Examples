#include <iostream>
#include <string>
#include "Security.h"

using namespace std;

#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

class Administrator {
public:
    static bool Login(string username, string password);

};

#endif