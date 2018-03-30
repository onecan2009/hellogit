#include <QCoreApplication>
#include <iostream>
#include <stdlib.h>
using namespace std;

double Div(double x, double y)
{
    if(y == 2.0)
    {
        throw y;
    }
    return x/y;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    {
        try
        {
            cout<<"7.3/2.0"<<Div(7.3, 2.0)<<endl;
            //cout<<"7.3/0.0"<<Div(7.3, 0.0)<<endl;
            cout<<"7.3/1.0"<<Div(7.3, 1.0)<<endl;
        }
        /*catch(double)
        {
            cout<<"exeption of deviding zero"<<endl;
        }*/
        catch(...)
        {
            cout<<"Error!"<<endl;
        }
    }
    return a.exec();
}
