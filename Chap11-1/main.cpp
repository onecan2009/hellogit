#include <QCoreApplication>
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    {
        try
        {
            int *array = new int[1000*1000*1000];
        }
        //catch(exception &e)
        catch(bad_alloc &e)
        {
            cout << "Error allocating memory." << endl;
            cout << e.what() << endl;
        }

    }
    
    return a.exec();
}
