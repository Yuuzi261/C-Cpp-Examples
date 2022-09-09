#ifndef SCIENCESTUDENT_H
#define SCIENCESTUDENT_H

#include <iostream>
#include <string>
#include "Student.h"

using std::string;
using std::istream;
using std::ostream;
using std::cout;
using std::endl;

class ScienceStudent : public Student {
public:
    ScienceStudent();
    ScienceStudent(string scienceDiscipline, string course);
    ScienceStudent(const ScienceStudent& scienceStudentObject);
    void setScienceDiscipline(string scienceDiscipline);
    void setCourse(string course);
    string getScienceDiscipline() const;
    string getCourse() const;
    ScienceStudent& operator=(const ScienceStudent& rtSide);
    friend istream& operator>>(istream& inStream, ScienceStudent& scienceStudentObject);
    friend ostream& operator<<(ostream& outStream, const ScienceStudent& scienceStudentObject);

private:
    string scienceDiscipline;
    string course;

};

#endif