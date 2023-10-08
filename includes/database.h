// 20204946이규성
//
// Created by 이규성 on 10/7/23.
//

#ifndef DATABASE_H
#define DATABASE_H

#include "student.h"
#include <vector>

class Database {
private:
    std::vector<Student> students;
    std::vector<Student> results;

public:
    void loadData(const std::string& filename);
    void saveData(const std::string& filename) const;

    int isDuplStudentID(std::string studentID);

    std::vector<Student> getAllStudents() const;

    void insert(const Student& student);

    std::vector<Student> searchByName(const std::string& name) const;
    std::vector<Student> searchByStudentID(const std::string& studentID) const;
    std::vector<Student> searchByAdmissionYear(const std::string& admissionYear) const;
    std::vector<Student> searchByDepartmentName(const std::string& departmentName) const;

    void sortByName();
    void sortByStudentID();
    void sortByAdmissionYear();
    void sortByDepartmentName();
};

#endif