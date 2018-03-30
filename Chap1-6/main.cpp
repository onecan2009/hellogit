#include <QCoreApplication>
#include <iostream>
using namespace std;

struct Person
{    char name[20];
    unsigned long id;
    float salary;};
void GetPerson(Person& p)
{    cout<<"Please enter a name for one person: \n";
    cin>>p.name;
    cout<<"Please enter id: \n";
    cin>>p.id;
    cout<<"Please enter his salary: \n";
    cin>>p.salary;}
void Print (const Person &p)
{
    cout<<p.name<<"    "<<p.id<<"    "<<p.salary<<"\n";
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    Person emp[3];
    for(int i = 0; i<3; i++)
    {
        GetPerson(emp[i]);
        Print(emp[i]);
    }
    return a.exec();
}
