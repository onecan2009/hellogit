#include <QCoreApplication>
#include <iostream>
using namespace std ;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    int intOne;
    int &rInt = intOne;
    intOne = 5;
    cout<<"intOne:"<<intOne<<"\n";
    cout<<"rInt"<<rInt<<"\n";

    rInt = 7;

    cout<<"intOne:"<<&intOne<<"\n";
    cout<<"rInt"<<&rInt<<"\n";

    return a.exec();
}
