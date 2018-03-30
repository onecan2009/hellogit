#include <QCoreApplication>
#include <iostream>
using namespace std;
class Increase
{
public:
    Increase(int x):value(x){}
    Increase& operator ++();
    Increase operator ++(int);
    void display(){cout<<"The value is  "<<value<<endl;}
private:
    int value;
};


Increase & Increase::operator ++()
{
    value++;
    return *this;
}

Increase Increase::operator ++(int)
{
    Increase temp(*this);
    value++;
    return temp;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    {
        Increase n(20);
        n.display();
        (n++).display();
        n.display();

        ++n;
        n.display();
        ++(++n);
        n.display();
        (n++)++;
        n.display();
    }
    
    return a.exec();
}
