/*
Recurrence Relation: T(n)= T(n-1) 
					 	 = T(n-2)
My recurrence relation defines that either it is T(n-1) if the value if selected from RL 
or it is T(n-2) if the value if selected from RH. The gap is because of PRIMING.

My function takes RH and RL array as input. Then it computes the revenue with all possible 
combinations of RH and RL values. The combination which gives the maximum revenue is selected 
at a particular index and the selected array is stored in a string memo named NAMING.
Then whole memo is calculated.... After that i traverse (reverse) the whole memo i.e memo and naming
and check whether the value for a week is selected from RH or RL. If it is selected from RH then i-1th week
is for priming and then so on upto last element.
No. of Subpromlems = n
Time for each problem = n
O(n^2) ---> I guess......


*/
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include <string.h>
#include <sstream>
#include <vector>
#include <cstring>
#include<bits/stdc++.h>

using namespace std;

int *memo;
string *naming;

int Total(int n)
{
	int sum = 0;
	for(int i=0;i<n;i++)
	{
		if(naming[i] !="PRIMING")
		{
			cout<<memo[i]<<endl;
			sum+=memo[i];
		}
		else
		{
			cout<<"PRIMING"<<endl;
		}
	}
	return sum;
}

void checkprime(int RH[],int RL[],int n)
{
	for(int i=n-1;i>=0;i--)
	{
		if(naming[i] == "HIGH")
		{
			if(i-1 < 0)
				break;
			//cout<<"DONE"<<endl;
			naming[i-1] = "PRIMING";
			//cout<<"DONE1"<<endl;
			i--;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(naming[i] == "LOW")
		{
			cout<<"Week "<<i+1<<" "<<naming[i]<<" "<<RL[i]<<endl;
		}
		else if(naming[i] == "HIGH")
		{
			cout<<"Week "<<i+1<<" "<<naming[i]<<" "<<RH[i]<<endl;	
		}
		else
		{
			cout<<"Week "<<i+1<<" "<<naming[i]<<endl;
		}
	}
	/*for(int i=0;i<n;i++)
		cout<<memo[i]<<endl;*/
}

int Revenue(int RH[], int RL[], int n, int i)
{
	
	if(i==0)
	{
		if(RH[i]>RL[i])
		{
			memo[i] = RH[i];
			naming[i] = "HIGH";
		}
		else
		{
			memo[i] = RL[i];
			naming[i] = "LOW";
		}
	}
	if(memo[i] != -1)
		return memo[i];
	else
	{
		int high; 
		int low;
		if(i > 1)
		{
			high = RH[i] + Revenue(RH,RL,n,i-2);
		}
		else
		{
			high = RH[i];
		}
		low = RL[i] + Revenue(RH,RL,n,i-1);
		if(high > low)
		{
			memo[i] = high;
			naming[i] = "HIGH";
		}
		else
		{
			memo[i] = low;
			naming[i] = "LOW";
		}
		return memo[i];	
	}
	
	
		
		
}



void Input_file(string name)
{
    ifstream infile;
    string input,garbage;
    int n;
   // int out =0;
    infile.open(name.c_str());
    infile>>garbage>>n;
    int RH[n];
    int RL[n];
    int arr_i = 0;
    int arr_j = 0;
    while(getline(infile,input))
    {
        istringstream st(input);
        string sample;
        int found;
        while(st >> sample)
        {
            if(sample == "RL")
            {
            	while(st >> sample)
                {
                	if(stringstream(sample) >> found)
                    {
                        RL[arr_i] = found;
                        //cout<<"RL "<<RL[arr_i];
                        arr_i++;                
                    }
                }
            }
            else
         {
         	while(st >> sample)
         	{
         		if(stringstream(sample) >> found)
            {
                RH[arr_j] = found;
                //cout<<"RH "<<RH[arr_j];
                arr_j++;
            }
        }
        }
        }
       

    }
    memo = new int[n];
    for(int i=0;i<n;i++)
    	memo[i] = -1;
    naming = new string[n];
    int total = Revenue(RH,RL,n,n-1);
    checkprime(RH,RL,n);
    cout<<"Total Revenue: "<<total<<endl;

}

int main()
{
	Input_file("Q1-input-D.txt");
	return 0;
}