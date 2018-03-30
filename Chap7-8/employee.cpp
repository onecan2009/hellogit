#include "employee.h"

employee::employee(const string & na)
{
    name = na;
    employeeNo++;
    individualEmpNo = employeeNo + 1000;

}
