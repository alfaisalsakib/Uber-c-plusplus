#include <iostream>

#include "DriverInfo.h"
#include "LocationType.h"
#include "QueueType.h"
#include "DriverType.h"

using namespace std;

void FindAlternative(LocationType<string> &L,string , string );

void Thanks()
{
    ifstream thanks;
    thanks.open("Thanks.txt");
    string thank;
    while(getline(thanks,thank))
    {
        cout<<thank<<endl;
    }
}

void Welcome()
{
    ifstream welcome;
    welcome.open("welcome.txt");

    string cmd;
    if(welcome.is_open())
    {
        while(getline(welcome,cmd))
        {
            cout<<cmd<<endl;
        }
    }
}

void Modify(DriverType drivers[],DriverType& driver,fstream& readDriverInfo,string destination,float TotalDistance,int CountDriver)
{
    cout<<"Do You Feel Comfortable with this Driver.Want to Rate the Driver.(y/n)"<<endl;

    here:

    string dis;
    cin>>dis;

    if(dis=="y")
    {
        driver.setCurrentLocation(destination);
        float newKm = driver.getDrivenKm()+TotalDistance;
        driver.setDrivenKm(newKm);
        driver.setRating(driver.getRating()+(.1));

        readDriverInfo.open("driverInfo.txt",ios::out);
        for(int i=0;i<CountDriver;i++)
        {
            drivers[i].rePrint(readDriverInfo);
        }
        readDriverInfo.close();

        Thanks();

    }
    else if(dis == "n")
    {
        driver.setCurrentLocation(destination);

        float newKm = driver.getDrivenKm() + TotalDistance;
        driver.setDrivenKm(newKm);

        driver.setFineCount(driver.getFineCount()+1);
        driver.setFineSum(driver.getFineSum()+100.5);
        driver.setRating(driver.getRating()-(.1));

        readDriverInfo.open("driverInfo.txt",ios::out);
        for(int i=0;i<CountDriver;i++)
        {
            drivers[i].rePrint(readDriverInfo);
        }
        readDriverInfo.close();

        Thanks();

    }
    else
    {
        cout<<"please type y for yes / n for no."<<endl;
        goto here;
    }
}

int main()
{
    fstream readDriverInfo;
    readDriverInfo.open("driverInfo.txt");

    ofstream writeTo;
    writeTo.open("driverType.txt");

    ifstream readTowns;
    readTowns.open("Towns.txt");

    ifstream mapInfo;
    mapInfo.open("CityMap.txt");

    ofstream topFive;
    topFive.open("TopFive.txt");

    Welcome();

    LocationType<string> LT;

    //Total towns
    int i=1;
    string town;
    if(readTowns.is_open())
    {
        cout<<"Suggested Towns"<<endl;
        while(readTowns>>town)
        {
            LT.AddVertex(town);
            cout<<i<<">> "<<town<<endl;
            i++;
        }

    }
    else
        cout<<"Error to open Towns.txt File"<<endl;
    //Total towns

    //Add Vertices
    string From,To;
    float Dis;
    if(mapInfo.is_open())
    {
        while(mapInfo>>From>>To>>Dis)
        {
            LT.AddEdge(From,To,Dis);
        }
    }
    else
        cout<<"Error to open CityMap.txt File"<<endl;
    //Add Vertices


    string currentLocation,destination;
    string currKey,desKey;

//    NewStart:


    v:
    top1:
    cout<<"Type Your Current Location Code : "<<endl;
    cin>>currKey;

    if(currKey=="1")
        currentLocation = "Uttara";
    else if(currKey=="2")
        currentLocation = "Mirpur";
    else if(currKey=="3")
        currentLocation = "Gulshan";
    else if(currKey=="4")
        currentLocation = "Bashundhara";
    else if(currKey=="5")
        currentLocation = "Ajimpur";
    else if(currKey=="6")
        currentLocation = "Motijheel";
    else if(currKey=="7")
        currentLocation = "Farmgate";
    else if(currKey=="8")
        currentLocation = "Dhanmondi";
    else
    {
        cout<<"<< Please Enter Valid Code >>"<<endl;
        goto top1;
    }

    top2:
    cout<<"Type Your Destination Place Code : "<<endl;
    cin>>desKey;

    if(desKey=="1")
        destination = "Uttara";
    else if(desKey=="2")
        destination = "Mirpur";
    else if(desKey=="3")
        destination = "Gulshan";
    else if(desKey=="4")
        destination = "Bashundhara";
    else if(desKey=="5")
        destination = "Ajimpur";
    else if(desKey=="6")
        destination = "Motijheel";
    else if(desKey=="7")
        destination = "Farmgate";
    else if(desKey=="8")
        destination = "Dhanmondi";
    else
    {
        cout<<"<< Please Enter Valid Code >>"<<endl;
        goto top2;
    }


    if(currentLocation == destination)
    {
        cout<<"<<< Same Place Invalid Input. >>>"<<endl;
        goto v;
    }
    float TotalDistance;
    if(LT.IsEdge(currentLocation,destination))
    {
         cout<<endl;
         cout<<"There is Direct way between "<<currentLocation<<" and "<<destination<<endl<<endl;
         TotalDistance = LT.GetWeight(currentLocation,destination);
         cout<<"Distance from "<<currentLocation<<" to "<<destination<<" = "<<TotalDistance<<"Km."<<endl;
    }
    else
    {
        cout<<"there is no Direct Way between "<<currentLocation<<" and "<<destination<<endl;

    }
           //count Drivers
    int countDriver =0;
    string tmp;

    while(readDriverInfo>>tmp)
        countDriver++;
    readDriverInfo.close();
    countDriver = countDriver/12;
            //count Drivers

    readDriverInfo.open("driverInfo.txt",ios::in); //writing mode ON
    DriverInfo df(readDriverInfo,topFive,countDriver); // DriverInfo
    df.AddDrivers();

    DriverType* drivers;
    drivers = df.GetDrivers();

    int nearDrivers = 0;
    for(int i=0;i<countDriver;i++)
    {
        if(currentLocation == drivers[i].getCurrentLocation())
        {
            nearDrivers++;
        }
    }

    cout<<"<< There are "<<nearDrivers<<" drivers in "<<currentLocation<<" >>"<<endl<<endl;

    for(int i=0;i<countDriver;i++)
    {
        if(currentLocation == drivers[i].getCurrentLocation())
        {
             drivers[i].print(writeTo);
        }
    }

    cout<<"<< Here are Some Top Rated Drivers for your Service. >>"<<endl;
    df.MostRated();

    cout<<endl;
    string DriverName;
    cout<<"Type Driver Name to Confirm the Driver / Type '1' for more categories of Drivers."<<endl;
    x:
    cin>>DriverName;

    bool key = false;
    for(int i=0;i<countDriver;i++)
    {
        if(DriverName == drivers[i].getName() || DriverName == "1")
        {
            key = true;
            break;
        }
    }

    if(key == false)
    {
        cout<<"<<< Please Enter Valid Name or Press 1. >>>"<<endl;
        goto x;
    }

    int TotalFare = 0;

    if(DriverName == "1")
    {
        cout<<endl;
        int option;
        cout<<"You can also choose your driver based on these categories. (Type Your option)"<<endl;

        here:

        cout<<"1>> Support passengers."<<endl;
        cout<<"2>> Car Type."<<endl;
        cout<<"3>> Fare Per Km."<<endl;
        cout<<"4>> Least Fined."<<endl<<endl;

        cin>>option;

        if(option==1)
        {
            cout<<"    You have selected option "<<option<<endl;

            for(int i=0;i<countDriver;i++)
            {
                cout<<"Name : "<<drivers[i].getName()<<endl;
                cout<<"Support : "<<drivers[i].GetSupportPass()<<endl;
            }

            cout<<"Type Driver Name to Confirm the Driver."<<endl;
            x1:
            cin>>DriverName;

            bool key = false;
            for(int i=0;i<countDriver;i++)
            {
                if(DriverName == drivers[i].getName())
                {
                    key = true;
                }
            }

            if(key == false)
            {
                cout<<"<<< Please Enter Valid Name. >>>"<<endl;
                goto x1;
            }


            for(int i=0;i<countDriver;i++)
            {
                if(drivers[i].getName() == DriverName)
                {
                    cout<<"You Have selected "<<DriverName<<endl;
                    cout<<"--- Full Detail of the Driver is Giver By ---"<<endl<<endl;

                    drivers[i].print(writeTo);

                    TotalFare = TotalDistance * drivers[i].GetFare();
                    drivers[i].setIncome(TotalFare);


                    cout<<"Your Total Cost is "<<TotalFare<<endl<<endl;

                    Modify(drivers,drivers[i],readDriverInfo,destination,TotalDistance,countDriver);
                }
            }

        }
        else if(option == 2)
        {
            cout<<"    You have selected option "<<option<<endl;

            for(int i=0;i<countDriver;i++)
            {
                cout<<"Name : "<<drivers[i].getName()<<endl;
                cout<<"CarType : "<<drivers[i].GetCarType()<<endl;
            }

            cout<<"Type Driver Name to Confirm the Driver."<<endl;
            x2:
            cin>>DriverName;

            bool key = false;
            for(int i=0;i<countDriver;i++)
            {
                if(DriverName == drivers[i].getName())
                {
                    key = true;
                }
            }

            if(key == false)
            {
                cout<<"<<< Please Enter Valid Name. >>>"<<endl;
                goto x2;
            }

            for(int i=0;i<countDriver;i++)
            {
                if(drivers[i].getName() == DriverName)
                {
                    cout<<"You Have selected "<<DriverName<<endl;
                    cout<<"--- Full detail of the Driver ---"<<endl<<endl;
                    drivers[i].print(writeTo);

                    TotalFare = TotalDistance * drivers[i].GetFare();
                    drivers[i].setIncome(TotalFare);

                    cout<<"Your Total Cost is "<<TotalFare<<endl<<endl;

                    Modify(drivers,drivers[i],readDriverInfo,destination,TotalDistance,countDriver);
                }
            }
        }
        else if(option == 3)
        {
            cout<<"    You have selected option "<<option<<endl;

            for(int i=0;i<countDriver;i++)
            {
                cout<<"Name : "<<drivers[i].getName()<<endl;
                cout<<"Fare : "<<drivers[i].GetFare()<<endl;
            }

            cout<<"Type Driver Name to Confirm the Driver."<<endl;
            x3:
            cin>>DriverName;

            bool key = false;
            for(int i=0;i<countDriver;i++)
            {
                if(DriverName == drivers[i].getName())
                {
                    key = true;
                }
            }
            if(key == false)
            {
                cout<<"<<< Please Enter Valid Name. >>>"<<endl;
                goto x3;
            }

            for(int i=0;i<countDriver;i++)
            {
                if(drivers[i].getName() == DriverName)
                {
                    cout<<"You Have selected "<<DriverName<<endl;
                    cout<<"--- Full detail of the Driver ---"<<endl<<endl;
                    drivers[i].print(writeTo);

                    TotalFare = TotalDistance*drivers[i].GetFare();
                    drivers[i].setIncome(TotalFare);

                    cout<<"Your Total Cost is "<<TotalFare<<endl<<endl;

                    Modify(drivers,drivers[i],readDriverInfo,destination,TotalDistance,countDriver);
                }
            }
        }
        else if(option ==4)
        {
            cout<<"you have selected Option "<<option<<endl;
            df.LeastFined();

            cout<<"Type Driver Name to Confirm the Driver."<<endl;
            x4:
            cin>>DriverName;

            bool key = false;
            for(int i=0;i<countDriver;i++)
            {
                if(DriverName == drivers[i].getName())
                {
                    key = true;
                }
            }

            if(key == false)
            {
                cout<<"<<< Please Enter Valid Name. >>>"<<endl;
                goto x4;
            }

            for(int i=0;i<countDriver;i++)
            {
                if(drivers[i].getName() == DriverName)
                {
                    cout<<"    You Have selected "<<DriverName<<endl;
                    cout<<"--- Full detail of the Driver ---"<<endl<<endl;
                    drivers[i].print(writeTo);

                    TotalFare = TotalDistance * drivers[i].GetFare();
                    drivers[i].setIncome(TotalFare);

                    cout<<"Your Total Cost is "<<TotalFare<<endl<<endl;

                    Modify(drivers,drivers[i],readDriverInfo,destination,TotalDistance,countDriver);
                }
            }
        }
        else
        {
            cout<<"Choosing Invalid options."<<endl;
            goto here;
        }
    }
    else
    {
        for(int i=0;i<countDriver;i++)
        {
            if(drivers[i].getName() == DriverName)
            {
                cout<<"You Have selected "<<DriverName<<endl;
                cout<<"---- Full detail of the Driver ----"<<endl<<endl;
                drivers[i].print(writeTo);

                TotalFare = TotalDistance*drivers[i].GetFare();
                drivers[i].setIncome(TotalFare);

                cout<<"Your Total Cost is "<<TotalFare<<endl<<endl;

                Modify(drivers,drivers[i],readDriverInfo,destination,TotalDistance,countDriver);
            }
        }
    }

    df.TopEarners();
    df.MostFined();
    df.LeastRated();

//    FindAlternative(LT,currentLocation,destination);

    //LT.FloydWarshal();

    return 0;
}


/*void FindAlternative(LocationType<string> &L,string c, string d)
{
    for(int k=0;k<8;k++)
    {
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                if((L[i][k] * L[k][j] != 0) && (i!=j))
                {
                    if(L[i][k]+L[k][j]<L[i][j] || L[i][j]==0)
                    {
                        L[i][j] = L[i][k] + L[k][j];
                    }
                }
            }
        }
    }
}
*/
