#ifndef DRIVERTYPE_CPP
#define DRIVERTYPE_CPP

#include "DriverType.h"
#include <stdlib.h>
#include <string>

DriverType::DriverType()
{
    income = 0;
}

void DriverType::initialization(string name,string phone,string fare,string carType,string carnumber,string supportPass)
{
    this->name = name;
    carNumber = carnumber;
    this->phone = phone;
    this->fare = fare;
    this->carType = carType;
    this->supportPass = supportPass;
}

void DriverType::print(ofstream& outFile)
{
    outFile<<"Name : "<<name<<endl;
    outFile<<"Phone : "<<phone<<endl;
    outFile<<"Fare : "<<fare<<endl;
    outFile<<"CarType : "<<carType<<endl;
    outFile<<"Car Number :"<<carNumber<<endl;
    outFile<<"Support passengers : "<<supportPass<<endl;
    outFile<<"total Distance Driven : "<<drivenDistance<<endl;
    outFile<<"Current Loacation : "<<currentLocation<<endl;
    outFile<<"Fine : "<<fineCount<<endl;
    outFile<<"Total Fine : "<<fineSum<<endl;
    outFile<<"Rating : "<<rating<<endl;

    cout<<"Name : "<<name<<endl;
    cout<<"Phone : "<<phone<<endl;
    cout<<"Fare : "<<fare<<endl;
    cout<<"CarType : "<<carType<<endl;
    cout<<"Car Number :"<<carNumber<<endl;
    cout<<"Support passengers : "<<supportPass<<endl;
    cout<<"total Distance Driven : "<<drivenDistance<<endl;
    cout<<"Current Loacation : "<<currentLocation<<endl;
    cout<<"Fine : "<<fineCount<<endl;
    cout<<"Total Fine : "<<fineSum<<endl;
    cout<<"Rating : "<<rating<<endl<<endl;
}

double DriverType::GetFare()
{
    double Fare = atof(fare.c_str());
    return Fare;
}

string DriverType::GetCarType()
{
    return carType;
}

string DriverType::GetSupportPass()
{
    return supportPass;
}
void DriverType::rePrint(fstream& outFile)
{
    outFile<<name<<" ";
    outFile<<phone<<" ";
    outFile<<fare<<" ";
    outFile<<carType<<" ";
    outFile<<carNumber<<" ";
    outFile<<supportPass<<" ";
    outFile<<drivenDistance<<" ";
    outFile<<currentLocation<<" ";
    outFile<<fineCount<<" ";
    outFile<<fineSum<<" ";
    outFile<<rating<<" ";
    outFile<<income<<endl;
}
void DriverType::setDrivenKm(float Km)
{
    drivenDistance = Km;
}

float DriverType::getDrivenKm()
{
    return drivenDistance;
}

string DriverType::getName()
{
    return name;
}

void DriverType::setCurrentLocation(string location)
{
    currentLocation = location;
}

string DriverType::getCurrentLocation()
{
    return currentLocation;
}

void DriverType::setFineCount(int fine)
{
    fineCount = fine;
}

int DriverType::getFineCount()
{
    return fineCount;
}

void DriverType::setFineSum(float fine)
{
    fineSum = fine;
}

float DriverType::getFineSum()
{
    return fineSum;
}

void DriverType::setRating(float rating)
{
    this->rating = rating;
}

float DriverType::getRating()
{
    return rating;
}

double DriverType::getIncome()
{
    return income;
}

void DriverType::setIncome(double incm)
{
    income = income + incm;
}

#endif // DRIVERTYPE_CPP
