#include "technician.h"

technician::technician(float rate, int hours, const string & na):employee(na)
{
    hourlyRate = rate;
    workHours = hours;
}
