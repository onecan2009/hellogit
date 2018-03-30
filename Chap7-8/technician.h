#ifndef TECHNICIAN_H
#define TECHNICIAN_H
#include "employee.h"

class technician : public employee
{
protected:
    float hourlyRate; //姣忓皬鏃堕叕閲?
    int workHours; //褰撴湀宸ヤ綔鏃舵暟
public:
    technician(float rate, int hours, const string & na);
    void pay() //璁＄畻鏈堣柂鍑芥暟
    {
        cout << hourlyRate * workHours << endl;
    }
    void displayStatus() //鏄剧ず浜哄憳淇℃伅
    {
        cout << "IndividualEmpNo: " << individualEmpNo << endl;
        cout << "Name: " << name << endl;
    }
};
#endif // TECHNICIAN_H
