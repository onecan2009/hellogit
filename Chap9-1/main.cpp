#include <QCoreApplication>
#include <iostream>
using namespace std;

template<class T>

void swap1(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int i = 3,j = 4;
    double x = 3.01, y = 4.03;
    cout<<i<<"    "<<j<<"\n";
    cout<<x<<"    "<<y<<"\n";
    swap1(i,j);
    swap1(x,y);
    cout<<i<<"    "<<j<<"\n";
    cout<<x<<"    "<<y<<"\n";
    
    return a.exec();
}
