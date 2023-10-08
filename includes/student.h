// 20204946이규성

#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
private:
    std::string name;
    std::string studentID;
    std::string birthYear;
    std::string department;
    std::string tel;

public:
    Student();
    Student(const std::string& name, const std::string& studentID, const std::string& birthYear, const std::string& department, const std::string& tel);

    std::string getName() const;
    std::string getStudentID() const;
    std::string getBirthYear() const;
    std::string getDepartment() const;
    std::string getTel() const;

    void setName(const std::string& newName);
    void setStudentID(const std::string& newID);
    void setBirthYear(const std::string& newBirthYear);
    void setDepartment(const std::string& newDepartment);
    void setTel(const std::string& newTel);
};

#endif