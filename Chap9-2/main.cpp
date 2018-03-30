#include <QCoreApplication>
#include <iostream>
using namespace  std;

template<class T> class Calc
{
public:
    T add(T x, T y);
    //Calc()

};

template<class T> T Calc<T>::add(T x,T y)
{
    cout<<x << " + "<<y<<" = "<<x+y<<endl;
    return x+y;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Calc<int> c1;
    int i = 3, j = 4;
    c1.add(i, j);
    return a.exec();
}
