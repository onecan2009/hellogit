
#include <QCoreApplication>
#include <iostream>

using namespace std;

class TDate
{
public:
    TDate();
    void SetDate(int m = 1, int d = 1, int y = 1998);
protected:
    int month;
    int day;
    int year;
};

TDate::TDate()
{
    month = 1;
    day = 1;
    year = 1;
}

void TDate::SetDate(int m, int d, int y)
{
    if(m>0 && m<13)
        month = m;
    if(d>0 && d<32)
        day = d;
    if(y>0 && y <3000)
        year = y;
}
void fn()
{
    TDate* pD;
    pD = new TDate;
    cout<<"The Date is created."<<endl;
    delete pD;
    cout<<"The Date is deleted."<<endl;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    {
        fn();
    }
    
    return a.exec();
}
