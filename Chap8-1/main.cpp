#include <QCoreApplication>
#include <iostream>
using namespace std;

class RMB
{
public:
    RMB(double d){yuan = d; jf = (d-yuan)/100;}
    RMB interest(double rate);
    RMB add(RMB d);
    void dispaly(){cout<<(yuan+jf/100.0)<<endl;}
    RMB operator+(RMB d){return RMB((yuan + d.yuan) +(jf + d.jf)/100);}
    RMB operator*(double rate)
    {
        return RMB((yuan+jf/100)*rate);
    }
private:
    unsigned int yuan;
    unsigned int jf;
};

RMB RMB::interest(double rate)
{
    return RMB((yuan +jf/100.0)*rate);
}

RMB RMB::add(RMB d)
{
    return RMB(yuan + d.yuan + jf/100.0 + d.jf/100.0);
}

RMB expense1(RMB principle, double rate)
{
    RMB interest = principle.interest(rate);
    return principle.add(interest);
}
RMB expense2(RMB principle, double rate)
{
    RMB interest = principle * rate;
    return (principle + interest);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    {
        RMB x(10.91);
        double yrate = 0.035;
        expense1(x, yrate).dispaly();
        expense2(x, yrate).dispaly();
    }
    return a.exec();
}
