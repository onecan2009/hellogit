#include <QCoreApplication>
#include <iostream>
using namespace std;
class Smallone
{
public:
    Smallone(int sm)
    {
        cout<<"Smallone constructing with a value of"<<sm<<"\n";
    }
};

void fn(int n)
{
    static Smallone sm(n);
    cout<<"In function fn with n = "<<n<<"\n";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    fn(10);
    fn(20);
    return a.exec();
}
