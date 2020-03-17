/*
		Description
	Recurrence relation : T(n) = 2 T(n/2)
	Algo:
	First i split the whole list into half and then continued to do so until i was left with only one element.
	Then i had a counter associated with every element. I incremented the counter at each step for each element
	In last, I calculated that if a counter value is greater than n/2 or not. 
	Time complexity -> O(n)
	Space complexity -> O(n)

*/
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include<fstream>
#include<string>
#include<string.h>
#include<sstream>
#include<time.h>
using namespace std;



void decode(int s, int n, int photos[], int counter[])
{
	if(s < n)
	{
		int c = s + (n-s) / 2;
		decode(s,c,photos,counter);
		decode(c+1,n,photos,counter);

		
	}
	if(s == n)
	{
		counter[photos[s]]++;
	}
	
	

}
void checker(int photos[],int counter[], int m, int n)
{
	bool suc = false;
	int val = -1;
	for(int k=0;k<m;k++)
	{
		//cout<<"[out]Counter of "<<k<<" is "<<counter[k]<<endl;
		if(counter[k] > n/2)
		{
			val = k;
			//cout<<"Counter of "<<k<<" is "<<counter[k]<<endl;
			//cout<<"Val is "<<val<<endl;
			suc = true;
		}
	}
	cout<<"[ ";
	for(int i=0;i<n;i++)
	{
		cout<<photos[i];
		if(i<n-1)
			cout<<", ";
	}
	cout<<" ]"<<endl;
	if(suc)
	{
		cout<<"Success"<<endl;
		cout<<"[ ";
		for(int k=0;k<n;k++)
		{
			if(photos[k] == val)
			{
				cout<<k;
				if(k<n-1)
					cout<<", ";
			}
		}
		cout<<" ]"<<endl;
	}
	else
	{
		cout<<"Failure"<<endl;
	}
}

int main()
{
	srand(time(NULL));
	int n, m;
	cout<<"Enter value of n   ";cin>>n;
	cout<<"Enter value of m   ";cin>>m;
	int photos[n] = {1, 2, 3, 3, 1, 2, 2, 1, 2, 2, 3, 2, 2, 1, 2};
	//int photos[n] = {1, 2, 3, 4, 5, 6, 6, 7, 8, 2, 1, 3, 4, 5, 2};
	//int photos[n];
	/*for(int i=0;i<n;i++)
	{
		photos[i] = rand() % m + 1;
		//cout<<photos[i]<<endl;
	}*/
	m++;
	int counter[m];
	for(int i=0;i<m;i++)
	{
		counter[i] = 0;
		//cout<<counter[i]<<endl;
	}
	decode(0,n-1,photos,counter);
	checker(photos,counter,m,n);
	return 0;
}

