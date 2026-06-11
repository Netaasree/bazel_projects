#include "student.h"
#include "student_database.h"

int main(){
    StudentDatabase db;

    Student s1("Netaasree",22);
    Student s2("Ram",21);
    Student s3("Hanuma",20);

    db.addStudent(s1);
    db.addStudent(s2);
    db.addStudent(s3);

    db.displayAllStudents();

    return 0;
}