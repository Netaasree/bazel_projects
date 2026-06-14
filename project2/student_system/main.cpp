#include "student.h"
#include "student_database.h"
#include <iostream>

int main(){
    StudentDatabase db;
    Student s1("sree", 22);
    Student s2("Ragu", 21);
    Student s3("venky", 20);

    db.addStudent(s1);
    db.addStudent(s2);
    db.addStudent(s3);
    int choice=0;
    while (choice!=5){
    std::cout << "\nStudent Management System\n";
    std::cout << "1. Add Student\n";
    std::cout << "2. Display Students\n";
    std::cout << "3. Search Student\n";
    std::cout << "4. Remove Student\n";
    std::cout << "5. Exit\n";

    std::cout<<"Enter choice: ";
    std::cin>>choice;
    if (choice==2){
        db.displayAllStudents();
    }
    if (choice==3){
        std::string name;
        std::cout<<"Enter student name: ";
        std::cin>>name;

        db.searchStudent(name);
    }
    if (choice==4){
        std::string name;
        std::cout<<"Enter student name: ";
        std::cin>>name;
        
        db.removeStudent(name);
    }
    }
}