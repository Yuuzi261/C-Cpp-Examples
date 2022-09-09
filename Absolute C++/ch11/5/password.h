#ifndef PASSWORD_H
#define PASSWORD_H

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

namespace {

    string password;
    bool isValid();

}

namespace Authenticate {

    void inputPassword();
    string getPassword();
    
}

#endif