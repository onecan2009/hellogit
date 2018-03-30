#include <QCoreApplication>
#include <iostream>
using namespace std;

int Factor(int n, int &rSquired, int&rCubed)
{
    if(n>20 || n<0)
        return true;
    rSquired = n*n;
    rCubed = n*n*n;
    return false;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    

    int number, squared, cubed;
    int error;
    cout<<"Enter a number(0-20)";
    cin>>number;
    error = Factor(number,squared,cubed);
    if(error)
        cout<<"Error encountered\n";
    else
    {
        cout<<"Number:"<<number<<"\n";
        cout<<"Square:"<<squared<<"\n";
        cout<<"cubed:"<<cubed<<"\n";
    }
    return a.exec();
}
