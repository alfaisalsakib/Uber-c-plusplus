#ifndef DRIVERINFO_CPP
#define DRIVERINFO_CPP

#include "DriverInfo.h"

DriverInfo::DriverInfo(fstream& readInfo,ofstream& top,int Total):readDriverInfo(readInfo) ,topFive(top)
{
    drivers = new DriverType[Total];
    length = 0;

    cout<<"Uber Driver"<<endl;
}

void DriverInfo::AddDrivers()
{
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

    if(readDriverInfo.is_open())
    {
        while(readDriverInfo>>name>>phone>>fare>>carType>>carNumber>>supportPass>>drivenDistance>>currentLocation>>fineCount>>fineSum>>rating>>income)
        {
            drivers[length].initialization(name,phone,fare,carType,carNumber,supportPass);
            drivers[length].setDrivenKm(drivenDistance);
            drivers[length].setCurrentLocation(currentLocation);
            drivers[length].setFineCount(fineCount);
            drivers[length].setFineSum(fineSum);
            drivers[length].setRating(rating);
            drivers[length].setIncome(income);
            length++;
        }

        readDriverInfo.close();
    }
    else
        cout<<"Error to open driverInfo.txt File"<<endl;

}

DriverType DriverInfo::SearchDriver(string nameTofind)
{
    int key = 0;
    for(int i=0;i<length;i++)
    {
        if(drivers[i].getName() == nameTofind)
        {
            key=i;
        }
    }

    return drivers[key];
}

void DriverInfo::LeastRated()
{
    VarType<float> vt;
    SortedType<float> sortInfo(length);
    QueueType<float> Q;
    QueueType<DriverType> Q1;

    for(int i=0;i<length;i++)
    {
        vt.Initialize(drivers[i].getRating());
        Q1.Enqueue(drivers[i]);
        sortInfo.PutItem(vt);
    }

    float* rate;
    rate = sortInfo.GetInfo();

    int d = length -  5;

    for(int i=length-1;i>=d;i--)
    {
        Q.Enqueue(*(rate+i));
    }

    float x;
    DriverType y;

    while(!Q.IsEmpty())
    {
        Q.Dequeue(x);
        while(!Q1.IsEmpty())
        {
            Q1.Dequeue(y);
            if(x == y.getRating())
            {
                topFive<<"LeastRated "<<y.getName()<<" == "<<y.getRating()<<endl;
                break;
            }
            else
            {
                Q1.Enqueue(y);
            }
        }
    }
}

void DriverInfo::MostFined()
{
    VarType<int> vt;
    SortedType<int> sortInfo(length);
    QueueType<int> Q;
    QueueType<DriverType> Q1;


    for(int i=0;i<length;i++)
    {
        vt.Initialize(drivers[i].getFineCount());
        Q1.Enqueue(drivers[i]);
        sortInfo.PutItem(vt);
    }

    int* Fine;
    Fine = sortInfo.GetInfo();

    for(int i=0;i<5;i++)
    {
        Q.Enqueue(*(Fine+i));
    }

    int x;
    DriverType y;

    while(!Q.IsEmpty())
    {
        Q.Dequeue(x);
        while(!Q1.IsEmpty())
        {
            Q1.Dequeue(y);
            if(x == y.getFineCount())
            {
                topFive<<"MostFined "<<y.getName()<<" == "<<y.getFineCount()<<endl;
                break;
            }
            else
            {
                Q1.Enqueue(y);
            }
        }
    }
}

void DriverInfo::LeastFined()
{
    VarType<int> vt;
    SortedType<int> sortInfo(length);
    QueueType<int> Q;
    QueueType<DriverType> Q1;


    for(int i=0;i<length;i++)
    {
        vt.Initialize(drivers[i].getFineCount());
        Q1.Enqueue(drivers[i]);
        sortInfo.PutItem(vt);
    }

    int* Fine;
    Fine = sortInfo.GetInfo();

    int d = length-5;

    for(int i=length-1;i>=d;i--)
    {
        Q.Enqueue(*(Fine+i));
    }


    int x;
    DriverType y;

    while(!Q.IsEmpty())
    {
        Q.Dequeue(x);
        for(int i=0;!Q1.IsEmpty();i++)
        {
            Q1.Dequeue(y);
            if(x == y.getFineCount())
            {
                //topFive<<"LeastFined "<<drivers[j].getName()<<endl;
                cout<<"LeastFined "<<y.getName()<<" >> "<<y.getFineCount()<<endl;
                break;
            }
            else
            {
                Q1.Enqueue(y);
            }
        }
    }

}
void DriverInfo::TopEarners()
{
    VarType<double> vt;
    SortedType<double> sortInfo(length);
    QueueType<double> Q;
    QueueType<DriverType> Q1;

    for(int i=0;i<length;i++)
    {
        vt.Initialize(drivers[i].getIncome());
        Q1.Enqueue(drivers[i]);
        sortInfo.PutItem(vt);
    }

    double* TopEarner;
    TopEarner = sortInfo.GetInfo();

    for(int i=0;i<5;i++)
    {
        Q.Enqueue(*(TopEarner+i));
    }

    double x;
    DriverType y;

    while(!Q.IsEmpty())
    {
        Q.Dequeue(x);
        while(!Q1.IsEmpty())
        {
            Q1.Dequeue(y);
            if(x == y.getIncome())
            {
                topFive<<"MostEarned "<<y.getName()<<" = "<<y.getIncome()<<endl;
                break;
            }
            else
            {
                Q1.Enqueue(y);
            }
        }
    }

}

DriverType* DriverInfo::GetDrivers()
{
    return drivers;
}

void DriverInfo::MostRated()
{
    VarType<float> vt;
    SortedType<float> sortInfo(length);
    QueueType<float> Q;
    QueueType<DriverType> Q1;


    for(int i=0;i<length;i++)
    {
        vt.Initialize(drivers[i].getRating());
        Q1.Enqueue(drivers[i]);
        sortInfo.PutItem(vt);
    }

    float* rate;
    rate = sortInfo.GetInfo();

    for(int i=0;i<5;i++)
    {
        Q.Enqueue(*(rate+i));
    }

    float x;
    DriverType y;

    while(!Q.IsEmpty())
    {
        Q.Dequeue(x);
        while(!Q1.IsEmpty())
        {
            Q1.Dequeue(y);
            if(x == y.getRating())
            {
                cout<<"MostRated "<<y.getName()<<" "<<y.getRating()<<endl;
                break;
            }
            else
            {
                Q1.Enqueue(y);
            }
        }
    }
}

DriverInfo::~DriverInfo()
{
    delete[] drivers;
}

#endif // DRIVERINFO_CPP
