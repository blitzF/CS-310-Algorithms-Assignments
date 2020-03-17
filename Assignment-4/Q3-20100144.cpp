/*
Recurrence Relation : T(n) = T(n-1)+ T(n-1)
So it defines that either an element is going to belong to first set or to the second....
For each element we place it in first set and then check if we can obtain such two sets 
whose difference is K and then we find all possibilities by including that element in 
other set too.

i compute the sets in one function and then i compute the elements of each set in other function
IDK why but i found this easy....
Time complexity O(2^n) -->(#problems x time for each problem)

*/
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include <string.h>
#include <sstream>
#include <climits>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h> 
using namespace std;

bool findSet(vector<int> n, vector<int> &set,int sum,int i)
{
	if(sum == 0)
	{
		return true;
	}
	if(i==0 && sum != 0)
	{
		return false;
	}
	if(n[i-1] > sum)
	{
		return findSet(n,set,sum,i-1);
	}
	if(findSet(n,set,sum,i-1) || findSet(n,set,sum-n[i-1],i-1))
	{
		if(find(set.begin(), set.end(), sum) != set.end())
		{
			//Do Nothing
		}
		else
		{
			set.push_back(sum);
		}
		return true;
	}
	return false;
}

bool difference(vector<int> numbers,int i,int set_A,int set_B,int k, int &sumA, int &sumB)
{
		if(i==0)
		{
			if(abs(set_A - set_B) == k)
			{
				sumA = set_A;
				sumB = set_B;
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
		return difference(numbers,i-1,set_A+numbers[i-1],set_B,k,sumA,sumB) ||  
		(difference(numbers,i-1,set_A,set_B+numbers[i-1],k,sumA,sumB));
			
		}

}


void Input_file(string name)
{
    ifstream infile;
    string input,garbage;
    int k;
    vector<int> n;
    infile.open(name.c_str());
    infile>>garbage>>k;
    while(getline(infile,input))
    {
        istringstream st(input);
        string sample;
        int found;
        while(st >> sample)
        {
           if(stringstream(sample) >> found)
                    {
                      n.push_back(found);             
                    }
        }
       

    }
    int size = n.size();
    int sumA,sumB;
    if(difference(n,size,0,0,k,sumA,sumB))
    {
    	cout<<"POSSIBLE"<<endl;
    	cout<<"Sum of SetA: "<<sumA<<endl;
		cout<<"Sum of SetB: "<<sumB<<endl;
    	vector<int> setA;
    	vector<int> final_setA;
    	vector<int> setB;
    	vector<int> final_setB;
    	cout<<"SET A: ";
    	{	
    	findSet(n,setA,sumA,size);
    	final_setA.push_back(setA[0]);
    	for(int i=1;i<setA.size();i++)
    		final_setA.push_back(setA[i]-setA[i-1]);
    	for(int i=0;i<final_setA.size();i++)
    		cout<<final_setA[i]<<" ";
    	}
    	cout<<endl;
    	cout<<"SET B: ";
    	{	
    	findSet(n,setB,sumB,size);
    	final_setB.push_back(setB[0]);
    	for(int i=1;i<setB.size();i++)
    		final_setB.push_back(setB[i]-setB[i-1]);
    	for(int i=0;i<final_setB.size();i++)
    		cout<<final_setB[i]<<" ";
    	}
    	cout<<endl;

    }
    else
    {
    	cout<<"NOT POSSIBLE"<<endl;
    }

    

}

int main()
{
	Input_file("Q3-input-A.txt");
	return 0;
}