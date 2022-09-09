#include <iostream>
#include <string>

using namespace std;

#ifndef SECURITY_H
#define SECURITY_H

class Security {
public:
    static int validate(string username, string password);

};

#endif