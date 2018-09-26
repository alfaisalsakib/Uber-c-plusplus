#ifndef DRIVERTYPE_H
#define DRIVERTYPE_H

#include <iostream>
#include <fstream>

using namespace std;

class DriverType
{
private:
    string name;
    string phone;
    string fare;
    string carType;
    string supportPass;
    string carNumber;
    float drivenDistance;
    string currentLocation;
    int fineCount;
    float fineSum;
    float rating;
    double income;
public:
    DriverType();
    void initialization(string name, string phone,string fare,string carType,string carNumber,string supportPass);
    void print(ofstream & outFile);
    void setDrivenKm(float Km);
    float getDrivenKm();
    void setCurrentLocation(string );
    string getCurrentLocation();
    void setFineCount(int );
    int getFineCount();
    void setFineSum(float );
    float getFineSum();
    void setRating(float );
    float getRating();
    string getName();
    double GetFare();
    void rePrint(fstream& outFile);
    string GetSupportPass();
    string GetCarType();
    int GetJourney();
    double getIncome();
    void setIncome(double );
};
#endif // DRIVERTYPE_H
