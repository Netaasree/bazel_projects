#ifndef STUDENT_H
#define STUDENT_H

#include<string>

class Student{
    public:
    int id;
    std::string name;
    int age;

    Student(int studentId,std::string studentName,int studentAge);
    
    void displayInfo();
};

#endif