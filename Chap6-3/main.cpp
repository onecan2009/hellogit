#include <QCoreApplication>
#include <iostream>
using namespace std;

class Student
{
public:
    static int number(){return noOfStudents;}
protected:
    char name[40];
    static int noOfStudents;
};

int Student::noOfStudents = 1;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    {
        Student s;
        cout<<s.number()<<endl;
        cout<<Student::number()<<endl;
    }

    return a.exec();
}
