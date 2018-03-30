#include <QCoreApplication>
#include <iostream>
using namespace std;

class Father
{
public:
    Father(){/*cout<<"Father is constructed!"<<endl;*/}
    virtual void Display(){cout<<"Father is displayed!"<<endl;}
    ~Father(){/*cout<<"Father is Destructed!"<<endl;*/}
};
class Son:public Father
{
public:
    Son(){/*cout<<"Son is constructed!"<<endl;*/}
    void Display(){cout<<"Son is displayed!"<<endl;}
    ~Son(){/*cout<<"Son is Destructed!"<<endl;*/}
};

class Daughter:public Father
{
public:
    Daughter(){/*cout<<"Daughter is constructed!"<<endl;*/}
    void Display(){cout<<"Daughter is displayed!"<<endl;}
    ~Daughter(){/*cout<<"Daughter is Destructed!"<<endl;*/}
};

class Eexecutor
{
public:
    void autoDisply(Father* pF){pF->Display();}
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    {
        Father f;
        Son s;
        Daughter d;
        f.Display();
        s.Display();
        //The following program is done by another developer
        //pointer directly
        Eexecutor e;
        e.autoDisply(&f);
        e.autoDisply(&s);
        e.autoDisply(&d);
    }

    return a.exec();
}
