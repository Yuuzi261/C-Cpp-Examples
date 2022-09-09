#include <iostream>
#include <string>
#include "administrator.h"

using namespace std;

int main(void) {

    using namespace SavitchEmployees;

    Administrator admin;
    string name, title, responsibility, supervisor;

    cout << "Enter the admin's name > ";
    cin >> name;
    admin.setName(name);
    admin.inputAdministratorData();

    cout << endl;
    admin.print();

    system("pause");
    return 0;

}