#include <iostream>
#include <string>
#include <cctype>
#include "password.h"

using namespace std;

namespace {

    bool isValid() {

        if(password.length() >= 8) {

            bool isNum = false;
            for(int i = 0;i < password.length();i++) {

                if(isdigit(password[i]))
                    isNum = true;

            }

            if(isNum)
                return true;
            else
                return false;

        }
        else
            return false;

    }

}

namespace Authenticate {

    void inputPassword( ) {

        do {

            cout << "Enter your password (at least 8 characters " <<
            "and at least one non-letter)" << endl;
            cin >> password;
            
        } while (!isValid( ));

    }

    string getPassword( ) {
        return password;
    }

}