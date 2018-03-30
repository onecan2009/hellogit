#include <QCoreApplication>
#include <iostream>
using namespace std;

class Date
{
public:
    Date(int y = 0, int m = 0, int d = 0)
    {
        cout << "constructor Date" << endl;
        m_year = y;
        m_month = m;
        m_day = d;
    }
    void showDate()
    {
        cout << m_year << "-" << m_month << "-" << m_day << endl;
    }
    Date operator+(Date & dt)
    {
        //cout << "call Operator +" << endl;
        Date temp;
        temp.m_year = m_year + dt.m_year;
        temp.m_month = m_month + dt.m_month;
        temp.m_day = m_day + dt.m_day;
        return temp;
    }

    Date & operator=(const Date & dt)
    {
        m_year = dt.m_year;
        m_month = dt.m_month;
        m_day = dt.m_day;
        return *this;
    }

    ~Date()
    {
        cout << "Distructor Date" << endl;
    }

    bool operator>(Date & dt)
    {
        if(m_year > dt.m_year)
            return true;
        else
            return false;
    }
    //++在前
    Date & operator++()
    {
        m_day++;
        return *this;
    }
    //++在后
    Date operator++(int)
    {
        Date temp = *this;
        this->m_day++;
        return temp;
    }
    //接收者是引用的时候，返回引用和返回值就有区别了，如果返回值接收者不能是引用
protected:
    int m_year;
    int m_month;
    int m_day;
};

class Time : public Date
{
public:
    Time(int y=0, int m=0, int day=0, int h=0, int min=0, int sec=0)
    {
        cout << "Time constructor" << endl;
        m_year = y;
        m_month = m;
        m_day = day;
        m_hours = h;
        m_minutes = min;
        m_second = sec;
    }
    ~Time()
    {
        cout << "Time distructor" << endl;
    }
    void showTime()
    {
        showDate();
        cout << "[" << m_hours << ":" << m_minutes << ":" << m_second << "]" << endl;
    }
protected:
    int m_hours;
    int m_minutes;
    int m_second;
};

class DTime : public Time
{
public:
    DTime(int y, int m, int d, int h, int min, int sec):Time(y, m, d, h, min, sec)
    { cout << "constructor DTime" << endl;}
    ~DTime()
    { cout << "distructor DTime" << endl;}

};


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    {
        DTime DT(1890, 7, 10, 20, 13, 22);
        DT.showTime();
        DT++;
        ++DT;
        DT.showTime();
    }
    return a.exec();
}
