#include <QCoreApplication>
#include <iostream>
using namespace std;

class SillyClass
{
public:
    SillyClass(int& i):ten(10), refI(i)
    {
        //ten = 10;
        refI = i;
    }
    void display(){cout<<"Ten is "<<ten<<endl; cout<<"refi is "<<refI<<endl;}
protected:
    const int ten;
    int& refI;
};
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int i = 0;
    SillyClass sc(i);
    sc.display();
    return a.exec();
}
