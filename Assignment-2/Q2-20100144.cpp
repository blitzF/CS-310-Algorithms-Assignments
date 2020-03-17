/*
//Data Structures Used//
I have used an array of ints to store the distances of Fuel stations.
//Algo Description//
Basically, I calculated the distance that I could travel with full tank. If that distance was less than the difference between the starting point 
and the destination then I could travel with just initial fuel. Otherwise i need to stop at fuel stations and get fuel. The decision that 
on which station to stop was according to the distance that could be travelled with full tank. If the distance was gretaer than the first 
station then it checks the distance for next station until the distance of next station is greater than the max distance that could be travelled
with initial fuel. After that, I stopped at previous station since the distance of next station was greater. Then I calculated the difference
between the station and the destination. I It helped to get an idea that how much fuel I need further. If the distance was greater than the distance 
that could be travelled with full tank then I'll acquire T litres again. Otherwise, I'll acquire the needed amount.
Formulas used :
Distance = tankcap / rate;
Time required to fill T litres = tankcap / F;
//Time and Space Complexity//
Time Complexity of the algo is : O(n) -> since I am using only one loop that operates on the difference between the travelled distance and the distance left.
Space Complextity of the algo is : O(n) -> since only array of size n is used.
*/




#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include<fstream>
#include<string>
#include<string.h>
#include<sstream>
using namespace std;

void TimeCal(double T, double R, double F, double stations[], double H)
{
	double tankCap, rate, FuelPerMin, Destination, distance, stat_coverdist, stat_coverpetrol, difference,totaltime =0;
	int index = 0;
	tankCap = T;
	rate = R;
	FuelPerMin = F;
	Destination = H;


	distance = tankCap / rate;
	//Distance that can be travelled with full tank
	difference = Destination - 0;
	//differece from where we at to where we have to go.
	while(difference > distance)
	{
		if(distance > stations[index])
		{
			index++;
		}
		else
		{
			if((index) < 0)
			{
				cout<<"Error"<<endl;
				exit(-1);
			}
			else
			{
				cout << "L"<<index+1<<" ";
				difference = Destination - stations[index];
				//we are now at station.
				stat_coverdist = distance - stations[index];
				stat_coverpetrol = stat_coverdist * rate;
				//Gives the remaining petrol in the tank.


				if(difference > distance)
				{
					tankCap = T - stat_coverpetrol;
					distance = tankCap / rate ;
					cout<<"Aquiring "<<tankCap<<" Litres of Pertrol from Here "<<endl;
					cout<<"It will take " <<(tankCap / FuelPerMin) << " minutes here. "<<endl;
					//cout<<(tankCap / FuelPerMin)<<endl;
					totaltime+= (tankCap / FuelPerMin);
					index++;
				}
				else
				{
					tankCap = (difference * rate) - stat_coverpetrol;
					cout<<"Aquiring "<<tankCap<<" Litres of Pertrol from Here "<<endl;
					cout<<"It will take " <<(tankCap / FuelPerMin) << " minutes here. "<<endl;
					//cout<<(tankCap / FuelPerMin)<<endl;
					totaltime+= (tankCap / FuelPerMin);

				}
			}
		}

	}
	cout<<"Total Time: "<< totaltime <<endl;


}

void Input_file(string name)
{
    ifstream infile;
    string input,garbage;
    double t,r,f,h;
    int n;
   // int out =0;
    infile.open(name.c_str());
    infile>>garbage>>t;
    //cout<<"T is "<<t<<endl;
    infile>>garbage>>r;
    //cout<<"R is "<<r<<endl;
    infile>>garbage>>f;
    //cout<<"F is "<<f<<endl;
    infile>>garbage>>n;
    //cout<<"N is "<<n<<endl;
    double arr[n];
    int arr_i = 0;
    while(getline(infile,input))
    {
        istringstream st(input);
        string sample;
        int found;
        while(st >> sample)
        {
            if(sample == "H")
            {
                st >>sample;
                if(stringstream(sample) >> found)
                    {
                        h=found;
                    //cout<<"value of H is: "<<found<<endl;
                    break;
                    }
            }
         if(stringstream(sample) >> found)
            {
                arr[arr_i] = found;
                //cout<<"found is "<<found<<endl;
                //cout<<arr[arr_i]<<endl;
                arr_i++;
            }
        }
       // cout<<endl;

    }
    //cout<<"value of H is "<<h<<endl;
    TimeCal(t,r,f,arr,h);

}

int main()
{
    string filename = "Q2test2.txt";
	Input_file(filename);

	return 0;
}
