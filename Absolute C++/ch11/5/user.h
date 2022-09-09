#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

using namespace std;

namespace {

    string username;
    bool isValid();

}

namespace Authenticate {

    void inputUserName();
    string getUserName();

}

#endif