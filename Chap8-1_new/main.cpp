#include <QCoreApplication>
#include <iostream>
#include <iomanip>
using namespace std;

class RMB
{
public:
    RMB(double d)
    {
        yuan = d*100;
        jf = d*100-yuan;
    }
    RMB interest(double rate);
    RMB add(RMB d);
    void dispaly()
    {
        cout<<(yuan+jf) /100.00<<endl;
    }
    RMB operator+(RMB d)
    {
        return RMB((yuan + d.yuan+jf + d.jf)/100.0);
    }
    RMB operator*(double rate)
    {
        return RMB( ( (yuan+jf)*rate/100.0 ) );
    }
private:
    unsigned int yuan;
    unsigned int jf;
};

RMB RMB::interest(double rate)
{
    return RMB( ( (yuan +jf)*rate/100.0));
}

RMB RMB::add(RMB d)
{
    return RMB( (yuan + d.yuan + jf + d.jf)/100.0);
}

RMB expense1(RMB principle, double rate)
{
    return principle.add(RMB(principle*rate));
}
RMB expense2(RMB principle, double rate)
{
    return RMB (principle * (1+rate));

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    {
        RMB x(100.89);
        double yrate = 0.035;
        expense1(x, yrate).dispaly();
        expense2(x, yrate).dispaly();
    }
    return a.exec();
}
