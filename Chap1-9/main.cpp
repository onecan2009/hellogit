#include <QCoreApplication>
#include <iostream>
using namespace std;

long fib(int x)
{
    if(x>2)
        return (fib(x-1)+fib(x-2));
    else
        return 1;
}

long gcd1(int x, int y)
{
    if(x%y == 0)
        return y;
    return gcd1(y, x%y);
}

long gcd2(int x, int y)
{
    int temp;
    while(y!=0)
    {
        temp = x%y;
        x = y;
        y = temp;
    }
    return x;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cout<<fib(20)<<endl;
    cout<<gcd1(100,25)<<endl;
    cout<<gcd2(100,25)<<endl;
    
    return a.exec();
}
