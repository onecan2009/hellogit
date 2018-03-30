#include <QCoreApplication>
#include <iostream>

using namespace std;

class Person
{public:
    char* name1;    //nick name
    void init()
    {name1 = new char[10];name2 = new char[10];name3 = new char[10];}
    void clear()
    {delete []name1; delete[] name2;delete[] name3;}
    char* Getname2(){cout<<name2<<"\n";return name2;}
    char* Getname3(){cout<<name3<<"\n";return name3;}
    void setname2(char* str){strcpy(name2,str);}
    void setname3(char* str){strcpy(name3,str);}
protected:
    char* name2;    //real name
private:
    char* name3;    /*user name*/};
int main(int argc, char *argv[])
{    QCoreApplication a(argc, argv);
    Person p;
    p.init();
    strcpy(p.name1 , "Obama");
    cout<<p.name1<<"\n";
    p.setname2("Bush");
    p.setname3("Clinton");
    p.Getname2();
    p.Getname3();
    p.clear();
    return a.exec();
}
