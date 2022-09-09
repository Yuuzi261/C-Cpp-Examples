#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include "UniversityStaff.h"

using std::string;
using std::istream;
using std::ostream;
using std::cout;
using std::endl;

class Student {
public:
    Student();
    Student(string UniversityName, int RegistrationNumber, UniversityStaff staff);
    Student(const Student& theObject);
    void setUniversityName(string UniversityName);
    void setRegistrationNumber(int RegistrationNumber);
    void setUniversityStaff(const UniversityStaff& staff);
    string getUniversityName() const;
    int getRegistrationNumber() const;
    UniversityStaff getUniversityStaff() const;
    Student& operator=(const Student& rtSide);
    friend istream& operator>>(istream& inStream, Student& studentObject);
    friend ostream& operator<<(ostream& outStream, const Student& studentObject);

protected:
    string UniversityName;
    int RegistrationNumber;
    UniversityStaff staff;

};

#endif