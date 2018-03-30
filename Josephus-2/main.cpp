#include <QCoreApplication>
#include "josephus.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Josephus jose;
    jose.Input();
    jose.GetWinner();

    return a.exec();
}
