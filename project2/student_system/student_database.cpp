#include "student_database.h"
#include <iostream>
#include <fstream>

void StudentDatabase::addStudent(Student newStudent) {
    students.push_back(newStudent);
    saveToFile();
}

void StudentDatabase::displayAllStudents() {
    for (Student student : students) {
        student.displayInfo();
    }
}

#
void StudentDatabase::searchStudent(int id) {
    for (Student student : students) {
        if (student.id == id) {
            student.displayInfo();
            return;
        }
    }

    std::cout << "Student not found" << std::endl;
}

#
void StudentDatabase::removeStudent(int id) {
    for (size_t i = 0; i < students.size(); i++) {
        if (students[i].id == id) {
            students.erase(students.begin() + i);
            saveToFile();
            std::cout << "Student removed" << std::endl;
            return;
        }
    }

    std::cout << "Student not found" << std::endl;
}

void StudentDatabase::saveToFile() {
    std::ofstream outFile("/home/netaasree/bazel_projects/project2/student_system/students.txt");

    for (Student student : students) {
        outFile << student.id << " "
                << student.name << " "
                << student.age << std::endl;
    }
}

void StudentDatabase::updateStudent(int id, int newAge) {
    for (Student &student : students) {
        if (student.id == id) {
            student.age = newAge;

            saveToFile();

            std::cout << "Student updated successfully!" << std::endl;
            return;
        }
    }

    std::cout << "Student not found" << std::endl;
}


void StudentDatabase::loadStudent(Student student) {
    students.push_back(student);
}