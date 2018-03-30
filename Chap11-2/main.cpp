#include <QCoreApplication>
#include <iostream>
#include<stdlib.h>
#include <exception>

using namespace std;

class myexception:public exception
{
public:
    char* description()
    {
            return "My exception happened";
    }
} myex;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    {
        try
        {
            throw myex;
        }
        catch (myexception& e)
        {
            cout << e.description() << endl;
        }

    }
    return a.exec();
}
