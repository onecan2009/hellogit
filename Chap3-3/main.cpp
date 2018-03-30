#include <QCoreApplication>
#include <iostream>
using namespace std;

class CCalculator
{
public:
    int add(int i, int j){cout<<(i+j)<<"\n"; return (i+j);}
   float add(float f, float k)
    {
        cout<<"from foat"<<(f+k)<<"\n";return (f+k);
    }
    double add(double d, double e)
    {
        cout<<"from double"<<(d+e)<<"\n";return (d+e);
    }
};
int main(int argc, char *argv[])
{    QCoreApplication a(argc, argv);
    CCalculator c;
    c.add(3.504, 5.125);

    CCalculator* p = &c;
    p->add(3,7);
    p->add(3.34,4.23);
  return a.exec();
}
