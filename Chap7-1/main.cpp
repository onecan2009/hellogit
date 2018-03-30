#include <QCoreApplication>
#include<iostream>
using namespace std;

class Advisor
{
    int noOfMeeting;
};

class Student
{
public:
    Student(char* pName = "noName")
    {
        strncpy(name, pName, sizeof(name));
        average = semesterHours = 0;
    }
    void addCourse(int hours, float grade)
    {
        average = (semesterHours*average+grade);    //Total score
        semesterHours += hours;                     //Study hour
        average /= semesterHours;                   //average score
    }
    int getHours()
    {
        return semesterHours;
    }
    float getAverage()
    {
        return average;
    }
    void display()
    {
        cout<<"name = \""<<name<<"\""<<", hours = "
                <<semesterHours<<", average = "<<average<<endl;
    }
protected:
    char name[40];
    int semesterHours;
    float average;
};

class GraduateStudent:public Student
{
public:
    int getQualifier()
    {
        return qualifierGrade;
    }
protected:
    Advisor advisor;
    int qualifierGrade;
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    {
        Student ds("Lo lee undergrade");
        GraduateStudent gs;
        ds.addCourse(3,2.5);
        ds.display();
        gs.addCourse(3, 3.0);
        gs.display();
    }
    return a.exec();
}
