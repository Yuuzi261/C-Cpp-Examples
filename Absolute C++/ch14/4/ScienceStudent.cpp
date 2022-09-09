#include <iostream>
#include <string>
#include "Student.h"
#include "ScienceStudent.h"

using std::string;
using std::istream;
using std::ostream;
using std::cout;
using std::endl;

ScienceStudent::ScienceStudent() {
    scienceDiscipline = "no science discipline yet";
    course = "no course yet";
}

ScienceStudent::ScienceStudent(string scienceDiscipline, string course) {
    this->scienceDiscipline = scienceDiscipline;
    this->course = course;
}

ScienceStudent::ScienceStudent(const ScienceStudent& scienceStudentObject) {
    scienceDiscipline = scienceStudentObject.scienceDiscipline;
    course = scienceStudentObject.course;
    UniversityName = scienceStudentObject.UniversityName;
    RegistrationNumber = scienceStudentObject.RegistrationNumber;
    staff = scienceStudentObject.staff;
}

void ScienceStudent::setScienceDiscipline(string scienceDiscipline) {
    this->scienceDiscipline = scienceDiscipline;
}

void ScienceStudent::setCourse(string course) {
    this->course = course;
}

string ScienceStudent::getScienceDiscipline() const {
    return scienceDiscipline;
}

string ScienceStudent::getCourse() const {
    return course;
}

ScienceStudent& ScienceStudent::operator=(const ScienceStudent& rtSide) {
    scienceDiscipline = rtSide.scienceDiscipline;
    course = rtSide.course;
    UniversityName = rtSide.UniversityName;
    RegistrationNumber = rtSide.RegistrationNumber;
    staff = rtSide.staff;
}

istream& operator>>(istream& inStream, ScienceStudent& scienceStudentObject) {
    cout << "Enter the name of university > ";
    inStream >> scienceStudentObject.UniversityName;
    cout << "Enter the registration number > ";
    inStream >> scienceStudentObject.RegistrationNumber;
    inStream >> scienceStudentObject.staff;
    cout << "Enter the science discipline > ";
    inStream >> scienceStudentObject.scienceDiscipline;
    cout << "Undergraduate or Postgraduate course? > ";
    inStream >> scienceStudentObject.course;
    return inStream;
}

ostream& operator<<(ostream& outStream, const ScienceStudent& scienceStudentObject) {
    outStream << "[Science Student]" << endl;
    outStream << "[University Name]: " << scienceStudentObject.UniversityName << endl;
    outStream << "[Registration Number]: " << scienceStudentObject.RegistrationNumber << endl;
    outStream << "[Proctor]: " << scienceStudentObject.staff << endl;
    outStream << "[Science Discipline]: " << scienceStudentObject.scienceDiscipline << endl;
    outStream << "[Course]: " << scienceStudentObject.course << endl;
    return outStream;
}