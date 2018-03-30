#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
using namespace std;

class employee
{
protected:
    string name;
    int individualEmpNo;
    float accumPay;
    static int employeeNo;
public:
    employee(const string & na);
    ~employee(){}
    virtual void pay()=0;
    virtual void displayStatus()=0;
};

#endif // EMPLOYEE_H
