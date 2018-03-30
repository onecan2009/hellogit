#include <QCoreApplication>
#include <iostream>
using namespace std;
#include <string.h>

class Student
{
public:
    Student(string &str);
    ~Student();
    void showName(){cout<<name<<endl;}
    static Student* getHeader(){return pFirst;}
    static Student* pFirst;
    static int noOfStudent;
    Student* pNext;
    string name;
};
Student::Student(string & str)
{
    name = str;
    pNext = NULL;
    noOfStudent++;
    cout<<noOfStudent<<endl;
    if(pFirst == NULL)
    {
        pFirst = this;
    }
    else
    {
        pNext = pFirst;
        pFirst = this;
    }
}
Student::~Student()
{
    noOfStudent--;
    if(NULL == pNext)
        delete pNext;
}
Student * Student::pFirst = NULL;
int Student::noOfStudent = 0;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    {
        int n = 5;
        for(int i = 0; i < n; i++)
        {
            string name;
            cout<<"name: ";
            cin>>name;
            Student* pt = new Student(name);
        }
        Student *p = Student::getHeader();
        while(p)
        {
            p->showName();
            p = p->pNext;
        }
        if(p->pFirst)
            delete p->pFirst;
    }
    return a.exec();
}
