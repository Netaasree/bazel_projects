#ifndef STUDENT_DATABASE_H
#define STUDENT_DATABASE_H

#include "student.h"
#include <vector>

class StudentDatabase{
    public:
        std::vector<Student> students;

        void addStudent(Student newstudent);
        void displayAllStudents();
        void searchStudent(std::string name);
        void removeStudent(std::string name);
        void saveToFile();
        void updateStudent(std::string name,int nameAge);
        void loadStudent(Student student);
};

#endif