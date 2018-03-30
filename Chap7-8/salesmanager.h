#ifndef SALESMANAGER_H
#define SALESMANAGER_H
#include "manager.h"
#include "salesman.h"


class salesmanager : public manager, public salesman
{
public:
    salesmanager(float mp, float rate, float total, const string & na);
    void pay()
    {
        cout << monthlyPay + CommRate * sales << endl;
    }
    void displayStatus()
    {
        cout << "IndividualEmpNo: " << individualEmpNo << endl;
        cout << "Name: " << name << endl;
    }
};

#endif // SALESMANAGER_H
