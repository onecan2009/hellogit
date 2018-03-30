#include <QCoreApplication>
#include<iostream>
using namespace std;

struct Person
{
    char name[20];
    unsigned long id;
    float salry;
};

static Person p;

const Person & GetPerson()
{
    cout<<"Please input a name:"<<"\n";
    cin>>p.name;
    cout<<"Please input id:"<<"\n";
    cin>>p.id;
    cout<<"Please input salary:"<<"\n";
    cin>>p.salry;
    return p;

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    const Person& sp = GetPerson();
    cout<<sp.name<<" salary: "<<sp.salry<<"\n";

    
    return a.exec();
}
