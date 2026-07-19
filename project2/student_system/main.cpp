#include "student.h"
#include "student_database.h"
#include <iostream>
#include <fstream>

int main() {
    StudentDatabase db;

    std::ifstream file("/home/netaasree/bazel_projects/project2/student_system/students.txt");

    int id;
    std::string name;
    int age;

    while (file >> id >> name >> age) {
        Student newStudent(id, name, age);
        db.loadStudent(newStudent);
    }
    file.close();

    int choice = 0;

    while (choice != 6) {
        std::cout << "\nStudent Management System\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. Display Students\n";
        std::cout << "3. Search Student\n";
        std::cout << "4. Remove Student\n";
        std::cout << "5. Update Student\n";
        std::cout << "6. Exit\n";

        std::cout << "Enter choice: ";
        std::cin >> choice;

        if (choice == 1) {
            int id;
            std::string name;
            int age;

            std::cout << "Enter ID: ";
            std::cin >> id;

            std::cout << "Enter Name: ";
            std::cin >> name;

            std::cout << "Enter Age: ";
            std::cin >> age;

            Student newStudent(id, name, age);

            db.addStudent(newStudent);

            std::cout << "Student added successfully!" << std::endl;
        }

        if (choice == 2) {
            db.displayAllStudents();
        }

        if (choice == 3) {
            int id;

            std::cout << "Enter student ID: ";
            std::cin >> id;

            db.searchStudent(id);
        }

        if (choice == 4) {
            int id;

            std::cout << "Enter student ID: ";
            std::cin >> id;

            db.removeStudent(id);
        }

        if (choice == 5) {
            int id;
            int age;

            std::cout << "Enter student ID: ";
            std::cin >> id;

            std::cout << "Enter new age: ";
            std::cin >> age;

            db.updateStudent(id, age);
        }
    }

    return 0;
}