// 20204946이규성

#include "database.h"
#include <iostream>
using namespace std;

//display 파트
void displayMainMenu();
void displaySearchMenu();

//menu들
void insertion(Database &db);
void search(Database &db);
void sorting(Database &database);

//전역 변수
int sorting_option = 1;

//main
int main(int argc, char *argv[]) {
    if (!(argc == 1 || argc == 2)) {
        std::cerr << "Error: Incorrect number of arguments.\n";
        return -1;
    }

    std::string filename;
    Database db;
    if (argc == 1)
        filename = "file1.txt";
    else
        filename = argv[1];
    db.loadData(filename);

    while (true) {
        displayMainMenu();
        int choice;
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1:
                insertion(db);
                break;
            case 2:
                search(db);
                break;
            case 3:
                sorting(db);
                break;
            case 4:
                db.saveData(filename);
                return (0);
            default:
                cout << "Enter 1~4 num\n";
        }
    }
}


//함수 구현
void displayMainMenu() {
    cout << "1. Insertion\n";
    cout << "2. Search\n";
    cout << "3. Sorting Option\n";
    cout << "4. Exit\n";
    cout << "> ";
}

void displaySearchMenu() {
    cout << "Search -\n";
    cout << "1. Search by name" << '\n';
    cout << "2. Search by student ID (10 numbers)\n";
    cout << "3. Search by admission year (4 numbers)\n";
    cout << "4. Search by department name\n";
    cout << "5. List All\n";
    cout << "> ";
}

void insertion(Database &db) {
    string name, studentID, birthYear, department, tel;

    cout << "Name ? ";
    getline(cin, name);
    if (name.length() > 15 || name.empty() || name.find(",") != std::string::npos) {
        cout << "Error: Name must be 1-15 characters long and should not contain ','.\n";
        return;
    }

    cout << "Student ID (10 digits)? ";
    cin >> studentID;
    if (studentID.length() != 10 || !all_of(studentID.begin(), studentID.end(), ::isdigit)) {
        cout << "Error: Student ID must be exactly 10 digits.\n";
        return;
    }

    cout << "Birth Year (4 digits) ? ";
    cin >> birthYear;
    if (birthYear.length() != 4 || !all_of(birthYear.begin(), birthYear.end(), ::isdigit)) {
        cout << "Error: Birth Year must be exactly 4 digits.\n";
        return;
    }

    cin.ignore();
    cout << "Department ? ";
    getline(std::cin, department);
    if (department.find(",") != std::string::npos) {
        cout << "Error: Department name should not contain ','.\n";
        return;
    }

    cout << "Tel ? ";
    cin >> tel;
    if (tel.length() > 12 || !std::all_of(tel.begin(), tel.end(), ::isdigit)) {
        cout << "Error: Tel must be 1-12 digits long.\n";
        return;
    }

    if (db.isDuplStudentID(studentID)) {
        cout << "Error : Already inserted. \n";
        return;
    }

    db.insert(Student(name, studentID, birthYear, department, tel));

    switch (sorting_option) {
        case 1:
            db.sortByName();
            return;
        case 2:
            db.sortByStudentID();
            return;
        case 3:
            db.sortByAdmissionYear();
            return;
        case 4:
            db.sortByDepartmentName();
            return;
        default:
            break;
    }
}

void search(Database &db) {
    displaySearchMenu();

    int choice;
    cin >> choice;
    cin.ignore();

    string searchTerm;
    vector<Student> searchResults;

    switch (choice) {
        case 1:
            cout << "Enter name to search: ";
            getline(cin, searchTerm);
            searchResults = db.searchByName(searchTerm);
            break;
        case 2:
            cout << "Enter student ID to search: ";
            cin >> searchTerm;
            searchResults = db.searchByStudentID(searchTerm);
            break;
        case 3:
            cout << "Enter admission year to search: ";
            cin >> searchTerm;
            searchResults = db.searchByAdmissionYear(searchTerm);
            break;
        case 4:
            cout << "Enter department name to search: ";
            getline(cin, searchTerm);
            searchResults = db.searchByDepartmentName(searchTerm);
            break;
        case 5:
            searchResults = db.getAllStudents();
            break;
        default:
            cout << "Invalid option. Returning to main menu." << '\n';
            return;
    }

    cout << "\n";
    printf("========================================================================== \n");
    printf("|NUM| ---- Name ---- | Student ID | -- Dept -- | Birth | ----- Tel ----- | \n");
    printf("========================================================================== \n");
    int i = 1;
    for (const auto &student: searchResults) {
        printf("|%-3d", i);
        printf("| %-15s", student.getName().c_str());
        printf("| %s ", student.getStudentID().c_str());
        printf("| %-10s ", student.getBirthYear().c_str());
        printf("| %5s ", student.getBirthYear().c_str());
        printf("| %15s |\n", student.getTel().c_str());
        i++;
    }
    printf("========================================================================== \n");

    cout << "Press enter to return to main menu...";
    cin.get();
}

void sorting(Database &db) {

    while (true) {
        std::cout << "Sorting Option\n";
        std::cout << "1. Sort by Name\n";
        std::cout << "2. Sort by Student ID\n";
        std::cout << "3. Sort by Admission Year\n";
        std::cout << "4. Sort by Department name\n";
        std::cout << "> ";
        std::cin >> sorting_option;
        std::cin.ignore();

        switch (sorting_option) {
            case 1:
                db.sortByName();
                std::cout << "Sorted by Name.\n";
                return;
            case 2:
                db.sortByStudentID();
                std::cout << "Sorted by Student ID.\n";
                return;
            case 3:
                db.sortByAdmissionYear();
                std::cout << "Sorted by Admission Year.\n";
                return;
            case 4:
                db.sortByDepartmentName();
                std::cout << "Sorted by Department name.\n";
                return;
            default:
                std::cout << "Enter 1~4\n";
                break;
        }
    }
}
