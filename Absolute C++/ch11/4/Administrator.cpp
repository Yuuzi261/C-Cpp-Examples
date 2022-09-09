#include <iostream>
#include <string>
#include "Security.h"
#include "Administrator.h"

using namespace std;

bool Administrator::Login(string username, string password) {

    if(Security::validate(username, password) == 2)
        return true;
    else
        return false;

}