#include <QCoreApplication>
#include<iostream>
using namespace std;

class Animal
{
public:
    Animal(){}
    void eat(){cout<<"eat"<<endl;}
};

class Giraffe:private Animal
{
public:
    Giraffe(){}
    //void eat(){Animal::eat();};
    void StechNeck(){cout<<"Strech neck"<<endl;}
};

class Cat:public Animal
{
public:
    Cat(){}
    void Meaw(){cout<<"Meaw"<<endl;}
};


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    {
        Cat c;
        c.eat();
        c.Meaw();
        Giraffe g;
        g.eat();
        g.StechNeck();
    }
    return a.exec();
}
