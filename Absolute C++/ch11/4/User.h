#include <iostream>
#include <string>
#include "Security.h"

using namespace std;

#ifndef USER_H
#define USER_H

class User {
public:
    static bool Login(string username, string password);

};

#endif