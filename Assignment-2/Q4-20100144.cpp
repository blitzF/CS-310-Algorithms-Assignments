/*
//Data Structures Used//
struct to get input from file
struct that contains all the information like ratio and total along with the length and prob.

//Algo Description//
I have made struct data type array of size n where n is number of racks. I am getting input from file in this array.
After passing this array and its size to function racks()., the calculation begins.
Then in the function i make array of struct rat type. Actually this struct comes handy when I have 
to compute the ratio i.e length / probablity. In this way i could keep a check of a particular 
ratio which belongs to a particular length and probablity.
After that i sorted the racks in their increasing order of ratio i.e Bigger->smaller
After that i implemented the given formula and calculated a varibale array named total.
This variable does the thing that it added the length of previous racks in the current rack.
After Calculating this, i multiplied total for each rack with its probability to calculate time
required for each rack. Lastly i added up all the times and this gave me expected time.

//Time and Space Complexity//
Time Complexity of the algo is : O(n) - > where n is the number of racks
Space Complextity of the algo is : O(nlogn)  - > O(n) for calulating raios, + O(nlogn) for sorting + O(n) for calculating expected time.
*/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include<fstream>
#include<string>
#include<string.h>
#include<sstream>
#include <bits/stdc++.h>
using namespace std;

struct data{
double length, prob;
};
struct rat {
double length, prob;
double ratios;
double total = 0;
int value;
};


bool compare(rat a, rat b)
{
    return(a.ratios < b.ratios);
}

void racks(data r[], int s)
{

    rat my[s];
    for(int i=0;i<s;i++)
    {
        my[i].value = i;
        my[i].length = r[i].length;
        my[i].prob = r[i].prob;
        my[i].ratios = r[i].length / r[i].prob;
        //cout<<ratios[i]<<endl;
    }
    sort(my,my+s,compare);
    my[0].total = my[0].length;
    for(int i=1;i<s;i++)
    {
        my[i].total = my[i-1].total + my[i].length;
    }
    double sol[s];
    double tot = 0;
    for(int i=0;i<s;i++)
    {
        my[i].value = my[i].value + 1;
    }
    for(int i=0;i<s;i++)
    {
        //cout << my[i].length << "   ";
        cout <<"Rack"<< my[i].value << "   ";
        sol[i] = my[i].total * my[i].prob;
        tot = tot + sol[i];
    }
    cout << endl << endl;
    cout<<"Expected Time: "<<tot<<endl;

}

void Input_file(string name)
{
    ifstream infile;
    string input,garbage;
    int n;
   // int out =0;
    infile.open(name.c_str());
    infile>>garbage>>n;
    //cout<<"N is "<<n<<endl;
    data arr[n];
    int i = 0 , j = 0;
    while(getline(infile,input))
    {
        istringstream st(input);
        string sample;
        double found;
        while(st >> sample)
        {
            if(sample == "p")
            {
               while(st >>sample)
                {
                    if(stringstream(sample) >> found)
                    {
                     arr[j].prob = found;
                     //cout<<"Prob is: "<<arr[j].prob<<endl;
                     j++;
                    //cout<<"value of H is: "<<found<<endl;
                    }
                }
            }
        else
        {
         if(stringstream(sample) >> found)
            {
                arr[i].length = found;
                //cout<<"found is "<<found<<endl;
                //cout<<"Length is: "<<arr[i].length<<endl;
                i++;
            }
        }
        }
       // cout<<endl;

    }
    //cout<<"value of H is "<<h<<endl;
    racks(arr,n);
}

int main()
{
    Input_file("Q4test2.txt");
    return 0;
}
