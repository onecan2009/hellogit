#include <QCoreApplication>
#include <iostream>
using namespace std;

class Student
{
public:
    Student(const char* pName = "noName")
    {
        cout<<"Constructor of Student"<<*pName<<"! \n";
    }
    ~Student(){cout<<"Destructor of Student"<<endl;}
};
class Teacher
{
public:
    Teacher(const char* pName = "noName")
    {
        cout<<"Constructor of Teacher"<<*pName<<"! \n";
    }
    ~Teacher(){cout<<"Destructor of Teacher"<<endl;}
};

void addCourse(Student& s)
{
    cout<<"From addCourse student!\n";
}

void addCourse(Teacher& t)
{
    cout<<"From addCourse teacher!\n";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    {
        addCourse(Teacher("Ding"));
        addCourse(Student("Ding"));
        Student s("Ding");
        Teacher t("Ding");
        addCourse(s);
        addCourse(t);
    }

    return a.exec();
}
