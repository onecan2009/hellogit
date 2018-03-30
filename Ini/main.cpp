#include <QCoreApplication>
#include <iostream>

using namespace std;

class A
{
public:
    A(int i){ i_a = i; cout<<"constructor from A"<<i_a<<endl;}
protected:
    int i_a;
};
class B
{
public:
    B(int i):a(i)
    {}
protected:
    int i_b;
    A a;
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    B b(3);

    return a.exec();
}
