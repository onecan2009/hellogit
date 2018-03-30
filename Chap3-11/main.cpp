#include <QCoreApplication>
#include <iostream>
using namespace std;

class Student
{
protected:
    int id;
public:
    Student(int d):id(d){}
    int getID(){cout<<id<<"\n";return id;}
};
class Tutor
{
public:
    Tutor(Student & s)
    {
        id = s.getID();
        cout<<id<<"\n";
    }
protected:
    int id;
};
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Student ra(1234);
    Tutor je(ra);
    return a.exec();
}
