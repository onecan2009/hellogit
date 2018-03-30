#include <QCoreApplication>
#include <iostream>
using namespace std;
class Student
{
public:
    Student(char* pName = "noName", int ssID = 0)
    {
        strncpy(name, pName, 40);
        name[sizeof(name)-1] = '\0';
        id = ssID;
        cout<<"Constructing new student"<<pName<<"\n";
    }

    Student(Student& s)
    {
        cout<<"Constructing copy of"<<s.name<<"\n";
        strcpy(name, "copy of ");
        strcat(name, s.name);
        id = s.id;
    }
    ~Student()
    {
        cout<<"Destructing "<<name<<"\n";
    }

protected:
    char name[40];
    int id;
};
void fn(Student s)
{
    cout<<"In function fn()\n";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    {
        Student randy("Randy", 1234);
        cout<<"Calling fn()\n";
        fn(randy);
        cout<<"Return from fn()\n";
    }
    return a.exec();
}
