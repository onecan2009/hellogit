#include <QCoreApplication>
#include <iostream>
using namespace std;

void swap (int &a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
    return;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    int x = 3;
    int y = 4;
    swap (x,y);
    cout<<"x = "<<x<<"\n";
    cout<<"y = "<<y <<"\n";

    return a.exec();
}
