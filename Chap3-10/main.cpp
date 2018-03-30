#include <QCoreApplication>
#include <iostream>
using namespace std;

class A
{
public:
    A(int j):age(j),num(age+1)
    {
        cout<<"age:"<<age<<", num:"<<num<<"\n";
    }
protected:
    int num;
    int age;
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    A sa(15);
    return a.exec();
}
