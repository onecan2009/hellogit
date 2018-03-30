#include <QCoreApplication>
#include <iostream>
using namespace std;

double& fn(const double & pd)
{
    static double ad = 32;
    ad += pd;
    cout<<"fn being called. the value is:"<<pd<<"\n";
    return ad;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    double d = 345.6;
    double& pa = fn(d);
    cout<<pa<<"\n";
    d = 55.5;
    pa = fn(d);
    cout<<pa<<"\n";

    return a.exec();
}
