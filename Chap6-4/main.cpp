#include <QCoreApplication>
#include <iostream>
using namespace std;

class Student
{
public:
    Student(char* pName);
    ~Student();
    static Student* findname(char* pNext);
protected:
    static Student* pFirst;
    Student* pNext;
    char name[40];
};

Student* Student::pFirst = NULL;

Student::Student(char* pName)
{
    strncpy(name, pName, sizeof(name));
    name[sizeof(name)-1] = '\0';
    pNext = pFirst;
    pFirst = this;
}

Student::~Student()
{
    if(pFirst == this)
    {
        pFirst = pNext;
        return;
    }
    for(Student* pS = pFirst; pS; pS = pS->pNext)
        if(pS->pNext == this)
        {
            pS->pNext = pNext;
            return;
        }
}

Student* Student::findname(char* pName)
{

    for(Student* pS= pFirst; pS; pS= pS->pNext)
    if(strcmp(pS->name,pName)==0)
    {
        return pS;
    }
    return (Student*) 0;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    {
        Student s1("Randy");
        Student s2("Jenny");
        Student s3("Kinsey");
        Student* pS = Student::findname("Kinsey");
        if(pS)
            cout<<"OK. "<<endl;
        else
            cout<<"no find."<<endl;
    }
    return a.exec();
}
