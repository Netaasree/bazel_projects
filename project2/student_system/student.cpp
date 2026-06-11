#include "student.h"
#include<iostream>

Student::Student(std::string studentName,int studentAge){
    name=studentName;
    age=studentAge;
}



void Student::displayInfo(){
    std::cout<<"Name:"<<name<<std::endl;
    std::cout<<"Age:"<<age<<std::endl;
}