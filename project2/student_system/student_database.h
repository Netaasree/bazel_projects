#ifndef STUDENT_DATABASE_H
#define STUDENT_DATABASE_H

#include "student.h"
#include <vector>

class StudentDatabase{
    public:
        std::vector<Student> students;

        void addStudent(Student newstudent);
        void displayAllStudents();
        void searchStudent(int id);
        void removeStudent(int id);
        void saveToFile();
        void updateStudent(int id,int nameAge);
        void loadStudent(Student student);
        int generateStudentId();
};

#endif