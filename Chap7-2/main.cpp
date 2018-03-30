#include <QCoreApplication>
#include <iostream>
using namespace std;

class Base
{
public:
    int m1;
protected:
    int m2;
private:
    int m3;
};

class PrivateClass: private Base
{
public:
    void test()
    {
        m1 = 1;
        m2 = 2;
        //m3 = 3;
    }
};

class DeivedFromPri:public PrivateClass
{
public:
    void test()
    {
        //m1 = 1;
        //m2 = 2;
        //m3 = 3;
    }
};

class ProtectedClass: protected Base
{
public:
    void test()
    {
        m1 = 1;
        m2 = 2;
        //m3 = 3;
    }
};

class DerivedFromPro:public ProtectedClass
{
public:
    void test()
    {
        m1 = 1;
        m2 = 2;
        //m3 = 3;
    }
};

class PublicClass: public Base
{
public:
    void test()
    {
        m1 = 1;
        m2 = 2;
        //m3 = 3;
    }
};

class DerivedFromPub: public PublicClass
{
public:
    void test()
    {
        m1 = 1;
        m2 = 2;
        //m3 = 3;
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    {
        PrivateClass priObj;
        //priObj.m1 = 1;
        //priObj.m2 = 2;
        //priObj.m3 = 3;

        ProtectedClass proObj;
        //priObj.m1 = 1;
        //priObj.m2 = 2;
        //priObj.m3 = 3;

        PublicClass pubObj;
        pubObj.m1 = 1;
        //pubObj.m2 = 2;
        //pubObj.m3 = 3;
    }
    return a.exec();
}
