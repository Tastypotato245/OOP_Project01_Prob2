// 20204946이규성

//
// Created by 이규성 on 10/7/23.
//

#include "database.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>

void Database::loadData(const std::string& filename) {
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        Student tempStudent;
        std::string line;
        while (std::getline(inFile, line)) {
            std::stringstream ss(line);
            std::string item;

            std::getline(ss, item, ',');
            tempStudent.setName(item);

            std::getline(ss, item, ',');
            tempStudent.setStudentID(item);

            std::getline(ss, item, ',');
            tempStudent.setBirthYear(item);

            std::getline(ss, item, ',');
            tempStudent.setDepartment(item);

            std::getline(ss, item, ',');
            tempStudent.setTel(item);

            students.push_back(tempStudent);
        }
        inFile.close();
    }
}

void Database::saveData(const std::string& filename) const {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const auto& student : students) {
            outFile << student.getName() << ","
                    << student.getStudentID() << ","
                    << student.getBirthYear() << ","
                    << student.getDepartment() << ","
                    << student.getTel() << "\n";
        }
        outFile.close();
    }
    else
    {
        std::cout << "Error : File was not opened. \n";
    }
}

void Database::insert(const Student& student) {
    students.push_back(student);
}

std::vector<Student> Database::searchByName(const std::string& name) const {
    std::vector<Student> result;
    for (const auto& student : students) {
        if (student.getName() == name) {
            result.push_back(student);
        }
    }
    return result;
}

std::vector<Student> Database::searchByStudentID(const std::string& studentID) const {
    std::vector<Student> result;
    for (const auto& student : students) {
        if (student.getStudentID() == studentID) {
            result.push_back(student);
        }
    }
    return result;
}
std::vector<Student> Database::searchByAdmissionYear(const std::string& admissionYear) const {
    std::vector<Student> result;
    for (const auto& student : students) {
        if (student.getStudentID().substr(0, 4) == admissionYear) {
            result.push_back(student);
        }
    }
    return result;
}
std::vector<Student> Database::searchByDepartmentName(const std::string& departmentName) const {
    std::vector<Student> result;
    for (const auto& student : students) {
        if (student.getDepartment() == departmentName) {
            result.push_back(student);
        }
    }
    return result;
}

std::vector<Student> Database::getAllStudents() const {
    return students;
}

int Database::isDuplStudentID(std::string studentID)
{
   for (const auto& student : students)
   {
       if (student.getStudentID() == studentID)
           return (1);
   }
   return (0);
}

bool compareByName(const Student& a, const Student& b) {return a.getName() < b.getName();}
bool compareByStudentID(const Student& a, const Student& b) {return a.getStudentID() < b.getStudentID();}
bool compareByAdmissionYear(const Student& a, const Student& b) {return a.getStudentID().substr(0, 4) < b.getStudentID().substr(0, 4);}
bool compareByDepartmentName(const Student& a, const Student& b) {return a.getDepartment() < b.getDepartment();}

void Database::sortByName() {std::sort(students.begin(), students.end(), compareByName);}
void Database::sortByStudentID() {std::sort(students.begin(), students.end(), compareByStudentID);}
void Database::sortByAdmissionYear() {std::sort(students.begin(), students.end(), compareByAdmissionYear);}
void Database::sortByDepartmentName() {std::sort(students.begin(), students.end(), compareByDepartmentName);}
