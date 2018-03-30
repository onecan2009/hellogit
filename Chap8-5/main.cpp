#include <QCoreApplication>
#include <iostream>

using namespace std;

class RMB
{
public:
    RMB(double value = 0.0);
    operator double(){return yuan + jf/100.0;}
    void display(){cout<<(yuan+ jf/100.0)<<endl;}
protected:
    unsigned int yuan;
    unsigned int jf;
};

RMB::RMB(double value)
{
    yuan = value;
    jf = (value - yuan)* 100+0.5;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    {
        RMB d1(2.0), d2(1.5), d3;
        d3 = RMB((double)d1 + (double)d2);
        d3 = d1 + d2;
        d3.display();
    }
    return a.exec();
}
