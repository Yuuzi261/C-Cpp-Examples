#include <iostream>
#include <string>
#include "UniversityStaff.h"
#include "Student.h"

using std::string;
using std::istream;
using std::ostream;
using std::cout;
using std::endl;

Student::Student() {
    UniversityName = "no name yet";
    RegistrationNumber = 0;
    staff = UniversityStaff();
}

Student::Student(string UniversityName, int RegistrationNumber, UniversityStaff staff) {
    this->UniversityName = UniversityName;
    this->RegistrationNumber = RegistrationNumber;
    this->staff = staff;
}

Student::Student(const Student& theObject) {
    UniversityName = theObject.UniversityName;
    RegistrationNumber = theObject.RegistrationNumber;
    staff = theObject.staff;
}

void Student::setUniversityName(string UniversityName) {
    this->UniversityName = UniversityName;
}

void Student::setRegistrationNumber(int RegistrationNumber) {
    this->RegistrationNumber = RegistrationNumber;
}

void Student::setUniversityStaff(const UniversityStaff& staff) {
    this->staff = staff;
}

string Student::getUniversityName() const{
    return UniversityName;
}

int Student::getRegistrationNumber() const {
    return RegistrationNumber;
}

UniversityStaff Student::getUniversityStaff() const {
    return staff;
}

Student& Student::operator=(const Student& rtSide) {
    UniversityName = rtSide.UniversityName;
    RegistrationNumber = rtSide.RegistrationNumber;
    staff = rtSide.staff;
}

istream& operator>>(istream& inStream, Student& studentObject) {
    cout << "Enter the name of university > ";
    inStream >> studentObject.UniversityName;
    cout << "Enter the registration number > ";
    inStream >> studentObject.RegistrationNumber;
    inStream >> studentObject.staff;
    return inStream;
}

ostream& operator<<(ostream& outStream, const Student& studentObject) {
    outStream << "[Student]" << endl;
    outStream << "[University Name]: " << studentObject.UniversityName << endl;
    outStream << "[Registration Number]: " << studentObject.RegistrationNumber << endl;
    outStream << "[Proctor]: " << studentObject.staff << endl;
    return outStream;
}
