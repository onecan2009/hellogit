#include <QCoreApplication>
#include <iostream>
using namespace std;

class Teacher;

class Student
{
public:
    friend class Teacher;
protected:
    float gpa;
    float hour;
};

class Teacher
{
public:
    void assignGrade(Student& s){s.gpa = 4.0;cout<<"Assign grade OK"<<endl;}
    void adjustHours(Student& s){s.hour = 1;cout<<"Adjust hour OK"<<endl;}
protected:
    int noOfStudent;
    Student* pList[100];
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    {
        Student s;
        Teacher t;
        t.adjustHours(s);
        t.assignGrade(s);
    }
    return a.exec();
}
