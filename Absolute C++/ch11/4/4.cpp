#include <iostream>
#include <string>
#include "Administrator.h"
#include "User.h"

using namespace std;

void input(string&, string&);

int main(void) {

    string user_input, username, password;

    cout << "[LOGIN INTERFACE]" << endl;
    cout << "[Administrator]: -a" << endl << "[User]: -u" << endl << "> ";
    cin >> user_input;

    if(user_input == "-a") {
        input(username, password);
        if(Administrator::Login(username, password))
            cout << "[Login Suceesfully]" << endl;
        else
            cout << "[Invalid Account or Password]" << endl;
    }
    else if(user_input == "-u") {
        input(username, password);
        if(User::Login(username, password))
            cout << "[Login Suceesfully]" << endl;
        else
            cout << "[Invalid Account or Password]" << endl;
    }
    else {
        cout << "[WRONG COMMAND]" << endl;
        exit(1);
    }

    system("pause");
    return 0;

}

void input(string& username, string& password) {

    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

}