#include <iostream>
#include <string>
#include "salariedemployee.h"
#include "administrator.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;

namespace SavitchEmployees {

    Administrator::Administrator() {
        SalariedEmployee();
        adminTitle = "No title yet";
        responsibility = "No responsibility yet";
        supervisorName = "No supervisor yet";
    }

    Administrator::Administrator(const string& theName, const string& theNumber, double theWeeklyPay, const string& adminTitle, const string& responsibility, const string& supervisorName) {
        SalariedEmployee(theName, theName, theWeeklyPay);
        this->adminTitle = adminTitle;
        this->responsibility = responsibility;
        this->supervisorName = supervisorName;
    }

    void Administrator::setSupervisor(const string& supervisorName) {
        this->supervisorName = supervisorName;
    }

    void Administrator::inputAdministratorData() {
        cout << "Enter the administrator's title > ";
        cin >> this->adminTitle;
        cout << "Enter the administrator's the company area of responsibility > ";
        cin >> this->responsibility;
        cout << "Enter the administrator's immediate supervisor > ";
        cin >> this->supervisorName;
    }

    void Administrator::print() const {
        cout << "[DATA OF ADMINISTRATOR]" << endl;
        cout << "[Name]: " << getName() << endl;
        cout << "[Title]: " << adminTitle << endl;
        cout << "[Responsibility]: " << responsibility << endl;
        cout << "[Immediate Supervisor]: " << supervisorName << endl;
    }

    void Administrator::printCheck( ) {
        setNetPay(salary);
        cout << "\n________________________________________________\n";
        cout << "Pay to the order of " << getName( ) << endl;
        cout << "The sum of " << getNetPay( ) << " Dollars\n";
        cout << "_________________________________________________\n";
        cout << "Check Stub NOT NEGOTIABLE \n";
        cout << "Employee Number: " << getSsn( ) << endl;
        cout << "Salaried Employee (Administrator). Regular Pay: " << salary << endl;
        cout << "_________________________________________________\n";
    }

}