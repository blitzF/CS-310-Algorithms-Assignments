/*
Recurrence relation: T(n-1)+T(m-1)
This defines that either the character of S3 belongs to S1 or S2 where n and m are sizes of S1 and S2 respectively.
So, I made a grid that denotes that given string is interleaving of other given strings or not..with given the condition
that ordering is also preserved. So if Grid value is true for n m index then it is valid interleaving.
After that i print the interleavings in a seperate function.
Time complexity -> O(nxm) where n is size o S1 and m is size of m
We divided problem into nxm (GRID SIZE) subproblems and it took O(1) time for each.


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
#include <bits/stdc++.h> 
using namespace std;

void printfunc(char const *S1,char const *S2,char const *S3,int size1,int size2,int size3,int check)
{
	if(size1 == 0 && size2 == 0)
		return;
	if(S1[0] == S3[0] && S2[0] == S3[0])
	{
		
		if(size1 > size2)
		{
			if(check != 1)
			{
				check = 1;	
				cout<<" S1";
			}
			cout<<S1[0];
			printfunc(S1+1,S2,S3+1,size1-1,size2,size3-1,check);
		}
		else
		{
			if(check != 2)
			{
				check = 2;
				cout<<" S2";
			}
			cout<<S2[0];
			printfunc(S1,S2+1,S3+1,size1,size2-1,size3-1,check);
		}
		

	}
	else if(S1[0] == S3[0])
	{
		if(check != 1)
		{
			cout<<" S1";
			check = 1;
		}
		cout<<S1[0];
		printfunc(S1+1,S2,S3+1,size1-1,size2,size3-1,check);
	}
	else if(S2[0] == S3[0])
	{
		if(check != 2)
		{
			cout<<" S2";
			check = 2;
		}
		cout<<S2[0];
		printfunc(S1,S2+1,S3+1,size1,size2-1,size3-1,check);
	}
}

bool compare(char const *S1,char const *S2,char const *S3,int size1,int size2,int size3)
{
	if(size3 != size1 + size2)
	{
		return false;
	}

	bool grid[size1+1][size2+1];
	//int check = 0;
	for(int i=0;i<=size1;i++)
		for(int j=0;j<=size2;j++)
			grid[i][j] =0;

	for(int i=0;i<=size1;i++)
	{
		for(int j=0;j<=size2;j++)
		{
			if(i==0 && j==0)  //BOTH S1 and S2 empty
			{
				grid[i][j] = true;
			}
			else if(i==0 && S2[j-1]==S3[j-1]) // S1 gets EMPTY and S3 matches with S2
			{
				grid[i][j] = grid[i][j-1];
				/*if(check != 2)
				{
					cout<<" S2";
					check = 2;
				}
				cout<<S2[j-1];*/
			}
			else if(S1[i-1] == S3[i-1] && j==0) // S2 gets EMPTY and S3 matches with S1
			{
				grid[i][j] = grid[i-1][j];
				/*if(check != 1)
				{
					cout<<" S1";
					check = 1;
				}
				cout<<S1[i-1];*/
			}
            else if(S1[i-1]==S3[i+j-1] && S2[j-1]!=S3[i+j-1])  // MATCH WITH S1 but not with S2
            {
                grid[i][j] = grid[i-1][j]; 
                /*if(check != 1)
				{
					cout<<" S1";
					check = 1;
				}
				cout<<S1[i-1];*/
            }
            else if (S1[i-1]!=S3[i+j-1] && S2[j-1]==S3[i+j-1]) // MATCH WITH S2 but not with S1
            {
                grid[i][j] = grid[i][j-1]; 
                /*if(check != 2)
				{
					cout<<" S2";
					check = 2;
				}
				cout<<S2[j-1];*/
            }
            else if (S1[i-1]==S3[i+j-1] && S2[j-1]==S3[i+j-1]) // MATCHES WITH BOTH
            {
                grid[i][j]=(grid[i-1][j] || grid[i][j-1]) ; 
            }
		}
	}
	return grid[size1][size2];
}


void Input_file(string name)
{
    ifstream infile;
    char const *s1;
    char const *s2;
    char const *s3;
    string sam1,sam2,sam3;
    int ss1,ss2,ss3;
    infile.open(name.c_str());
    infile >> sam1;
    infile >> sam2;
    infile >> sam3;
    infile.close();
    s1 = sam1.c_str();
    s2 = sam2.c_str();
    s3 = sam3.c_str();
    ss1 = strlen(s1);
    ss2 = strlen(s2);
    ss3 = strlen(s3);
    if(compare(s1,s2,s3,ss1,ss2,ss3))
    {
    	cout<<" VALID"<<endl;
    	printfunc(s1,s2,s3,ss1,ss2,ss3,0);
    }
    else
    {
    	cout<<"INVALID"<<endl;
    }


}

int main()
{
	Input_file("test.txt");
	return 0;
}