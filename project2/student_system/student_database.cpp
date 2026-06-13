#include "student_database.h"
#include <iostream>

void StudentDatabase::addStudent(Student newStudent) {
    students.push_back(newStudent);
}

void StudentDatabase::displayAllStudents() {
    for (Student student : students) {
        student.displayInfo();
    }
}

void StudentDatabase::searchStudent(std::string name) {
    for (Student student : students) {
        if (student.name == name) {
            student.displayInfo();
            return;
        }
    }

    std::cout << "Student not found" << std::endl;
}

void StudentDatabase::removeStudent(std::string name) {
    for (int i = 0; i < students.size(); i++) {
        if (students[i].name == name) {
            students.erase(students.begin() + i);
            std::cout << "Student removed" << std::endl;
            return;
        }
    }

    std::cout << "Student not found" << std::endl;
}