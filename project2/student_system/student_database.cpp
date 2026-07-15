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
    for (size_t i = 0; i < students.size(); i++) {
        if (students[i].name == name) {
            students.erase(students.begin() + i);
            saveToFile();
            std::cout << "Student removed" << std::endl;
            return;
        }
    }

    std::cout << "Student not found" << std::endl;
}

void StudentDatabase::saveToFile(){
    std::ofstream outFile("/home/netaasree/bazel_projects/project2/student_system/students.txt");
    /*middle student is variable*/
    for(Student student:students){
        outFile<<student.name<<" "<<student.age<<std::endl;
    }
}

void StudentDatabase::updateStudent(std::string name,int newAge){
    for(Student &student: students){
        if(student.name==name){
            student.age=newAge;
            
            saveToFile();

            std::cout<<"Student updated successfully!"<<std::endl;
            return;
        }
    }
    std::cout<<"Student not Found"<<std::endl;
}

void StudentDatabase::loadStudent(Student student){
    students.push_back(student);
}