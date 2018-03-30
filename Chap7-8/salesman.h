#ifndef SALESMAN_H
#define SALESMAN_H
#include "employee.h"

class salesman : virtual public employee
{
protected:
    float CommRate; //鎸夐攢鍞鎻愬彇閰噾鐨勭櫨鍒嗘瘮
    float sales; //褰撴湀閿€鍞
public:
    salesman(float rate, float total, const string & na);
    void pay() //璁＄畻鏈堣柂鍑芥暟
    {
        cout << CommRate * sales << endl;
    }
    void displayStatus() //鏄剧ず浜哄憳淇℃伅
    {
        cout << "IndividualEmpNo: " << individualEmpNo << endl;
        cout << "Name: " << name << endl;
    }
};

#endif // SALESMAN_H
