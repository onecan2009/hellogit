#include <QCoreApplication>
#include <iostream>
using namespace std;

class Student
{
public:
    Student(char* pName = "noName")
    {
        cout<<"Create one student"<<endl;
        strncpy(name,pName, 40);
        name[39] = '\0';
        noOfStudents++;
        cout<<noOfStudents<<endl;
    }
    ~Student()
    {
        cout<<"Destruct one student"<<endl;
        noOfStudents--;
        cout<<noOfStudents<<endl;
    }
    static int number()
    {
        return noOfStudents;
    }
protected:
    static int noOfStudents;
    char name[40];

};

int Student::noOfStudents = 0;

void fn()
{
    Student s1;
    Student s2;
    cout<<Student::number()<<endl;
}
void fn(Student& s1, Student& s2)
{
    int i = 0;
    i++;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    {
        Student s1, s2;
        fn(s1, s2);
        //fn();
        cout<<Student::number()<<endl;
    }
    return a.exec();
}
