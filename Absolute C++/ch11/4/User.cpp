#include <iostream>
#include <string>
#include "Security.h"
#include "User.h"

using namespace std;

bool User::Login(string username, string password) {

    if(Security::validate(username, password) == 1 || Security::validate(username, password) == 2)
        return true;
    else
        return false;

}