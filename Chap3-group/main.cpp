#include <QCoreApplication>
#include <iostream>
#include <string>
using namespace std;
class student
{
public :
    student(const char* pName)
    {
        m_Name.insert(0,pName);
    }
    student()
    {
       cout << "A student constructed\n";
    }
    ~student()
    {
       cout << "A student destructed\n";
    }
    void setName(const char *pName)
    {
        m_Name.insert(0,pName);
    }
    void showName()
    {
        cout << "student: " << m_Name << endl;
    }
protected:
    string m_Name;
};

class teacher
{
public :
    teacher()
    {
        cout << "A teacher constructed\n";
    }
    teacher(const char *pName)
    {
        m_Name.insert(0, pName);
    }
    ~teacher()
    {
        cout << "A teacher destructed\n";
    }
    void setName(const char *pName)
    {
        m_Name.insert(0,pName);
    }
void showName()
    {
        cout << "teacher: " << m_Name << endl;
    }
protected :
    string m_Name;
};

class group
{
public :
    group()
    {
        cout << "A group constructed\n";
    }
    group(const char *sName, const char *tName) : s1(sName) , t1(tName)
    {
        cout<<"A group constructed with "<<sName<<" "<<tName<<endl;
    }
    ~group()
    {
        cout << "A group destructed\n";
    }
    void showTeacher()
    {
        t1.showName();
    }
    void showStudent()
    {
        s1.showName();
    }
protected :
    student s1;
    teacher t1;
};
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    group *pgrp = new group("Luck", "Hans");
    pgrp->showTeacher();
    pgrp->showStudent();
    delete pgrp;

    return a.exec();
}
