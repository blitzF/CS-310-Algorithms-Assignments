/*
Recurrence Relation: T(n)=T(n-1)+T(n-1)+c
						 = 2T(n-1)+c
						 ----->I guess
I guess the above recurrence relation means that one value is getting selected and it's cost is c(const) then recursion
goes for the remaining values (left & right). So (T(n-1)) for them....

Function takes in the given values of m as vector and the the length (n). After this i store the relative 
values associated with the cuts grater than the given value and cost of cuts that are smaller than present
value as same as their length...This way i recursively find the mimimum cost required to cut the ruler in
given lengths. I couldnt print the ordering because it was very difficult to back track the ordering that 
gave the minimum cost.. I tried to store orderings in vector named output but couldnt do so....
Time required to compute is n! (problems * time) --> Havent memoized.... 
Otherwise,,,, TIME COMPLEXITY : O(n^4)  (n^2) --> Probelms and (n^2)---> Time for each problem.
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
using namespace std;

int ruler(int n, vector<int> m,vector<int> &output)
{
	int max_out = INT_MAX;
	int loop = 0;
	int size = m.size();
	if(size == 0)
	{

		return 0;
	}
	if(size == 1)
	{
		return n;
	}
	for(int i=0;i<size;i++)
	{
		vector<int> left;
		vector<int> right;
		output.push_back(m[i]);	
		for(int j=0;j<size;j++)
		{
			if(m[j] < m[i])
			{
				left.push_back(m[j]);
			}
			else if (m[j] > m[i])
			{
				right.push_back(m[j]-m[i]);
			}
			
		}
			int final_cost = n+ruler(m[i],left,output)+ruler(n-m[i],right,output);
			if(final_cost < max_out)
				{
					max_out = final_cost;
				}
	}
	return max_out;
}


void Input_file(string name)
{
    ifstream infile;
    string input,garbage;
    int n;
    infile.open(name.c_str());
    infile>>garbage>>n;
    vector<int> m;
    while(getline(infile,input))
    {
        istringstream st(input);
        string sample;
        int found;
        while(st >> sample)
        {
           if(stringstream(sample) >> found)
                    {
                      m.push_back(found);             
                    }
        }
       

    }
    vector<int> o;
    cout<<ruler(n,m,o)<<endl;

}


int main()
{
	Input_file("Q2-input-A.txt");
	
	
	return 0;
}