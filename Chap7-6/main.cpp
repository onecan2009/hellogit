#include <QCoreApplication>
#include <iostream>
using namespace std;

class Obj1
{
public:
    Obj1(){cout<<"Obj1"<<endl;}
};

class Obj2
{
public:
    Obj2(){cout<<"Obj2"<<endl;}
};

class Base1
{
public:
    Base1(){cout<<"Base1"<<endl;}
};

class Base2
{
public:
    Base2(){cout<<"Base2"<<endl;}
};

class Base3
{
public:
    Base3(){cout<<"Base3"<<endl;}
};

class Base4
{
public:
    Base4(){cout<<"Base4"<<endl;}
};

class Derived:public Base2, public Base4, public Base1, public Base3
{

public:
    Derived(){cout<<"Derived OK"<<endl;}

protected:
        Obj2 o2;
        Obj1 o1;

};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    {
        Derived d;

    }
    return a.exec();
}
