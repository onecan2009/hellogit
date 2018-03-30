#include "salesmanager.h"

salesmanager::salesmanager(float mp, float rate, float total, const string & na)
    :manager(mp, na),salesman(rate, total, na),employee(na)
{}
