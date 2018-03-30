#include <QCoreApplication>


//#include <iostream>
using namespace std;

int sub(int x , int y ){return (x-y);}

double sub(double x, double y ){return (x-y);}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
   cout<<sub(5, 3)<<endl;
    cout<<sub(15.01, 5.04)<<endl;

    return a.exec();
}
