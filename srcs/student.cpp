// 20204946이규성

#include "student.h"

Student::Student() : name(""), studentID(""), birthYear(""), department(""), tel("") {}

Student::Student(const std::string& name, const std::string& studentID, const std::string& birthYear, const std::string& department, const std::string& tel)
        : name(name), studentID(studentID), birthYear(birthYear), department(department), tel(tel) {}

std::string Student::getName() const {return name;}
std::string Student::getStudentID() const {return studentID;}
std::string Student::getBirthYear() const {return birthYear;}
std::string Student::getDepartment() const {return department;}
std::string Student::getTel() const {return tel;}

void Student::setName(const std::string& newName) { name = newName; }
void Student::setStudentID(const std::string& newID) { studentID = newID; }
void Student::setBirthYear(const std::string& newBirthYear) { birthYear = newBirthYear; }
void Student::setDepartment(const std::string& newDepartment) { department = newDepartment; }
void Student::setTel(const std::string& newTel) { tel = newTel; }
