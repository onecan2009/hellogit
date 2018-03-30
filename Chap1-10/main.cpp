#include <QCoreApplication>
#include <iostream>
using namespace std;

//int add(int x = 0, int y = 0){return x+y;}

double add(double x = 0, double y = 0){return x+y;}

int add(int x=3, int y=2, int z){return x + y + z;}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //cout<<add(5)<<endl;
    //cout<<add(3.3,4.4)<<endl;
   // cout<<add();
    return a.exec();
}
