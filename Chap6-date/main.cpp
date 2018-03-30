#include <QCoreApplication>
#include <iostream>
using namespace std;
class Date
{
public:
    Date(){cout << "Constructor Date()" << endl;}
    ~Date(){cout << "Distructor ~Date()" << endl;}
    Date(int y, int m, int d)
    {
        year = y;
        month = m;
        day = d;
    }
    void showDate()
    {
        cout << year << "-" << month << "-" << day << endl;

    }
    void setDate(int y, int m, int d)
    {
        year = y;
        month = m;
        day = d;
    }
    Date operator+(const Date & dt) const
    {
        cout << "Date operator+(Date & d1, Date & d2)" << endl;
        Date temp;
        temp.year = year + dt.year;
        temp.month = month + dt.month;
        temp.day = day + dt.day;
        return temp;
    }
    Date & operator=(const Date & dt)
    {
        year = dt.year;
        month = dt.month;
        day = dt.day;
        return *this;
    }

    Date & operator++()
    {
        year++;
        month++;
        day++;
        return *this;
    }
    Date operator++(int)
    {
        cout << "operator++(int)" << endl;
        Date temp = *this;
        year++;
        month++;
        day++;
        return temp;
    }
    friend void set_year(Date &, int);
    //friend Date & operator++(Date &);
    //friend Date operator++(Date &, int);
protected:
    int year;
    int month;
    int day;
};

void set_year(Date & dt, int y)
{
    dt.year = y;
}
/*
//++dt
Date & operator++(Date & dt)
{
    dt.year++;
    dt.month++;
    dt.day++;
    return dt;
}
//dt++
Date operator++(Date & dt, int)
{
    Date temp = dt;
    dt.year++;
    dt.month++;
    dt.day++;
    return temp;
}
*/
class EastDate: public Date
{
public:
    EastDate()
    {
        cout << "Constructor EastDate()" << endl;
    }
    ~EastDate()
    {
        cout <<"Distructor ~EastDate()" << endl;
    }
    void showEastDate()
    {
        year += 5;
        month += 5;
        day += 5;
        cout << year << "-" << month << "-" << day << endl;
    }
};


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    {
        EastDate ed;
        Date *pD = &ed;
        pD->setDate(1280, 12, 5);
        ed.showEastDate();
        pD->showDate();
     }
    return a.exec();
}
