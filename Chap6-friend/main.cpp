#include <QCoreApplication>

#include <iostream>
using namespace std;


class Person {
 private:
     string name;
     int age;
public:
    Person(const string & na, int ag)
    {
        name = na;
        age = ag;
    }
    friend void compare_age(Person & p1, Person & p2);
    friend class Teacher;
};

void compare_age(Person & p1, Person & p2)
{
    if(p1.age>p2.age)//访问私有变量
    {  cout << p1.name << " is older than " << p2.name << endl;}
    else if(p1.age == p2.age)//访问私有变量
    {	cout << p1.name <<" is the age of"<< p2.name << endl;}
    else
    {	cout << p1.name <<" is younger than "<< p2.name << endl;}
}


class Teacher
{
public:
    void assignAge(int age, Person & per);
    void print_info(Person & per);
};

void Teacher::assignAge(int age, Person & per)
{
    per.age = age;
}
void Teacher::print_info(Person & per)
{
    cout << "name: " << per.name << endl;;
    cout << "age: " << per.age << endl;
}



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    {
        Person P1("Hans", 33);
        Person P2("Mark", 36);
        compare_age(P1, P2);
        Teacher T1;
        T1.assignAge(35, P1);
        T1.print_info(P1);
    }

    return a.exec();
}
