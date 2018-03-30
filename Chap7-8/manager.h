#ifndef MANAGER_H
#define MANAGER_H
#include "employee.h"

class manager:virtual public employee
{
protected:
    float monthlyPay; //鍥哄畾鏈堣柂鏁?
public:
    manager(float mp, const string & na);
    void pay() //璁＄畻鏈堣柂鍑芥暟
    {
        cout << monthlyPay << endl;
    }
    void displayStatus() //鏄剧ず浜哄憳淇℃伅
    {
        cout << "IndividualEmpNo: " << individualEmpNo << endl;
        cout << "Name: " << name << endl;
    }
};

#endif // MANAGER_H
