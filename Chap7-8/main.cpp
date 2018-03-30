#include <QCoreApplication>
#include <iostream>
#include "employee.h"
#include "salesman.h"
#include "manager.h"
#include "technician.h"
#include "salesmanager.h"

using namespace std;


int employee::employeeNo = 0;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    {
        technician tec1(100, 50, "Look");
        salesman sal1(0.2, 100000, "Sara");
        manager  mag1(8000.0, "Tom");
        salesmanager salmg1(5000, 0.1, 100000, "Pott");
        employee *Em[] = {&tec1, &sal1, &mag1, &salmg1};
        for(int i = 0; i < 4; i++)
        {
            Em[i]->displayStatus();
            Em[i]->pay();
            cout << endl;
        }
    }
    return a.exec();
}
