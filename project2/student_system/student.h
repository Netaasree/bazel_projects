#ifndef STUDENT_H
#define STUDENT_H

#include<string>

class Student{
    public:
    std::string name;
    int age;

    Student(std::string studentName,int studentAge);
    
    void displayInfo();
};

#endif