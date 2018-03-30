#include <QCoreApplication>
#include <iostream>
using namespace std;

int nextStudentID = 0;
class StudentID
{
public:
    StudentID(int id)
    {
        value = id;
        //value = ++nextStudentID;
        cout<<"Constructor from student id "<<value<<"\n";
    }
    ~StudentID()
    {
        //--nextStudentID;
        cout<<"Destructing student id"<<value<<"\n";
    }
protected:
    int value;
};

class Student
{
public:
    Student(char* pName = "noName", int ssID = 0):id(ssID)
    {
        //cout<<"Constructing student "<<pName<<"\n";
        strncpy(name,pName,sizeof(name));
        name[sizeof(name)-1]='\0';

    }
protected:
    char name[20];
    StudentID id;
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    {
        Student s("Randy",9818);
        Student t("Jenny");
    }

    return a.exec();
}
