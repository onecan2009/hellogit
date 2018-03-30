#include <QCoreApplication>
#include <iostream>
using namespace std;

class Person
{
public:
    Person(char*pN)
    {
        cout<<"Constructing "<<pN<<"\n";
        pName = new char[strlen(pN)+1];
        if(pName!=0)
            strcpy(pName, pN);
    }
    Person(Person & p)
    {
        cout<<"Copying "<<p.pName<<" into its own block\n";
        pName = new char[strlen(p.pName)+1];
        if(pName!=0)
            strcpy(pName, p.pName);
    }

    ~Person()
    {
        cout<<"Destructing "<<pName<<"\n";
        //pName[0] = '\0';
        delete[] pName;
    }
protected:
    char* pName;
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    {
        Person p1("Randy");
        Person p2 = p1;
    }

    return a.exec();
}
