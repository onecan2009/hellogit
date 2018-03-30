#include <QCoreApplication>
#include <iostream>
using namespace std;

class TDate
{
public:
    TDate();
    TDate(int d);
    TDate(int m, int d);
    TDate(int m, int d, int y);
protected:
    int month;
    int day;
    int year;
};

TDate::TDate()
{
    month = 4;
    day = 15;
    year = 1995;
    cout<<month<<"/"<<day<<"/"<<year<<"\n";
}

TDate::TDate(int d)
{
    month = 4;
    day = d;
    year = 1995;
    cout<<month<<"/"<<day<<"/"<<year<<"\n";
}

TDate::TDate(int m, int d)
{
    month = m;
    day = d;
    year = 1995;
    cout<<month<<"/"<<day<<"/"<<year<<"\n";
}

TDate::TDate(int y =1995 , int m =1 , int d =1 )
{
    month = m;
    day = d;
    year = y;
    cout<<month<<"/"<<day<<"/"<<year<<"\n";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    TDate aday;
    TDate bday(10);
    TDate cday(2,12);
    TDate dday(1,2,2015);

    return a.exec();
}
