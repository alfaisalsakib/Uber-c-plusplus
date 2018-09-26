#ifndef DRIVERINFO_H
#define DRIVERINFO_H

#include "DriverType.h"
#include "VarType.h"
#include "SortedType.h"
#include "QueueType.h"

#include <fstream>

using namespace std;

class DriverInfo
{
private:
    fstream& readDriverInfo;
    ofstream& topFive;
    int length;
    DriverType* drivers;
public:
    DriverInfo(fstream& , ofstream& ,int length);
    ~DriverInfo();
    void AddDrivers();
    DriverType SearchDriver(string );
    void LeastRated();
    void MostRated();
    void MostFined();
    void LeastFined();
    void TopEarners();
    DriverType* GetDrivers();
};

#endif // DRIVERINFO_H

#include "VarType.cpp"
#include "SortedType.cpp"
