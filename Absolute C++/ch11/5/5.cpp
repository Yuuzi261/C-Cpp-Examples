#include <iostream>
#include <string>
#include "user.h"
#include "password.h"

using namespace std;

int main( ) {

    using namespace Authenticate;
    inputUserName( );
    inputPassword( );
    cout << "Your username is " << getUserName( ) <<
    " and your password is: " <<
    getPassword( ) << endl;

    system("pause");
    return 0;

}