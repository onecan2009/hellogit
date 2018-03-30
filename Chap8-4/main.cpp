#include <QCoreApplication>
#include <iostream>
using namespace std;

class Increase
{
public:
    Increase(int x):value(x){}
    friend Increase & operator ++(Increase &);
    friend Increase operator ++(Increase&, int);
    void display(){cout<<"The value is "<<value<<endl;}
private:
    int value;
};

Increase & operator ++(Increase &a)
{
    a.value++;
    return a;
}


Increase operator ++(Increase& a, int)
{
    Increase temp(a);
    a.value;
    return temp;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    {
        Increase n(20);
        n.display();
        (n++).display();
        ++n;
        n.display();
        ++(++n);
        n.display();

    }
    return a.exec();
}
