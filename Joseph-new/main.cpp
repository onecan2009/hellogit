#include <QCoreApplication>
#include "josephus.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int boys, begin, m;
    while(boys<2||begin<1||m<1||m>boys)
    {
        cout <<"please input \nnumber of boys, begin position,interval per count :\n" ;
        cin >> boys >> begin >>m;
    }
    Josephus jose(boys, begin, m);
    jose.GetWinner();

    return a.exec();
}
