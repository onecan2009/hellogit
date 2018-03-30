#include <QCoreApplication>
#include "josephus.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Josephus jose;
    jose.GetWinner();

    return a.exec();
}
