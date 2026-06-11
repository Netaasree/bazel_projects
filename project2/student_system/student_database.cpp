#include "student_database.h"
#include<iostream>

void StudentDatabase::addStudent(Student newStudent){
    students.push_back(newStudent);
}

void StudentDatabase::displayAllStudents(){
    for (Student student:students){
        student.displayInfo();
    }
}