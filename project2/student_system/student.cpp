#include "student.h"
#include<iostream>

Student::Student(int studentId, std::string studentName, int studentAge) {
    id = studentId;
    name = studentName;
    age = studentAge;
}


void Student::displayInfo(){
std::cout << "ID:" << id << std::endl;
std::cout << "Name:" << name << std::endl;
std::cout << "Age:" << age << std::endl;
}