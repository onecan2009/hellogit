#include <QCoreApplication>
#include <iostream>
using namespace std;

class Person
{
/*private:
    Person(){}*/
public:
    static void  dispaly()  {cout<<"C is : "<<c<<endl;}
protected:
   static int c;

};

int Person::c = 0;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    Person::dispaly();
    Person p;
    p.dispaly();

    return a.exec();
}
