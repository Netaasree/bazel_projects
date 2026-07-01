#include "student.h"
#include "student_database.h"
#include <iostream>
#include<fstream>

int main(){
    StudentDatabase db;
    std::ifstream file("/home/netaasree/bazel_projects/project2/student_system/students.txt");
    std::ofstream outFile("/home/netaasree/bazel_projects/project2/student_system/students.txt",std::ios::app);
    outFile<<"Test 100"<<std::endl;
    std::string name;
    int age;

    while(file>>name>>age){
    Student newStudent(name,age);
    db.addStudent(newStudent);
    };

    if(file.is_open()){
        std::cout<<"File opened successfully!"<<std::endl;
    }
    else{
        std::cout<<"File not opened"<<std::endl;
    }
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
    if(choice==1){
        std::string name;
        int age;

        std::cout<<"Enter Name: ";
        std::cin>>name;

        std::cout<<"Enter Age: ";
        std::cin>>age;

        Student newStudent(name,age);

        db.addStudent(newStudent);
        std::cout<<"Student added successfully!"<<std::endl;
    }
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