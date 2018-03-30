#include <QCoreApplication>
#include <iostream>
using namespace std;

class TDate
{
public:
    void Set(int m, int d, int y)
    {
        month = m; day = d; year = y;
    }
    int Isleapyear()
    {
        return ((year%4 == 0 && year%100!=0)||(year%400==0));
    }
    void Print()
    {
        cout<<month<<"/"<<day<<"/"<<year<<"\n";
    }
private:
    int month;
    int day;
    int year;
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    TDate d;
    d.Set(2,4,2015);
    d.Print();

    return a.exec();
}
