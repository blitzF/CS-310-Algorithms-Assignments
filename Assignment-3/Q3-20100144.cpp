/*
		Description
	Recurrence relation : T(n) = 4T(n/2) + C
	Algo: 
	First i took input from user and asked the indeices of the first block space. Then i calculated 
	the quadrant in which the block space was placed. After calculating that i placed the blocks in such a 
	way that they get placed in the remaining three quadrants. After that now each quadrant has a block space
	then i use the recursion to place blocks in all the quadrants (going sub quadrant wise). tricky part was to 
	calculate the indices on which the element was to be placed.

	time complexity -> O(n^2)
	space complexity -> O(n^2)

*/
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

char **board;
char element = 'A';
void create(int n, int r, int c)
{
	board = new char* [n];
	for(int i=0;i<n;i++)
		board[i] = new char[n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			
			board[i][j] = '0';
			if(i==r && j==c)
				board[i][j]=' ';
		}
	}
}
void print(int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
}

void boardfunc(int n, int sr, int sc,int r,int c)
{
	//int r,c;
	if(n==2)
	{
		element++;
		for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(board[sr+i][sc+j] == '0')
			//if(board[i][j] == '0')	
			{
				//board[i][j] = element;
				board[sr+i][sc+j] = element;
				//element++;
			}
		}
		
	}

	return;
	}
	//Base case ends here
	//For 1st Quad
	if(r < sr + n/2 && c < sc+ n/2)  
	{
		element++;
		board[sr + n/2][sc+ (n/2) - 1] = element;
		board[sr + n/2][sc+n/2] = element;
		board[sr + (n/2) -1][sc + n/2] = element;

	}
	//For 2nd Quad
	else if(r < sr + n/2 && c >= sc + n/2) 
	{
		element++;		
		board[sr+n/2][sc + (n/2) - 1] = element;
		board[sr + n/2][sc + n/2] = element;
		board[sr+n/2-1][sc + (n/2) -1] = element;
	}
	//For 3rd Quad
	 else if(r >= sr + n/2 && c < sc + n/2)
	{
		element++;		
		board[sr + (n/2) - 1][sc + (n/2)] = element;
		board[sr + (n/2)][sc + n/2] = element;
		board[sr + (n/2) - 1][sc + (n/2) -1] = element;
	}
	//For 4th Quad
	else if(r >= sr + n/2 && c >= sc + n/2) 
	{
		element++;		
		board[sr+ (n/2) -1][sc + (n/2)] = element;
		board[sr + (n/2)][sc + (n/2) -1] = element;
		board[sr + (n/2) - 1][sc + (n/2) - 1] = element;
	}

/*	boardfunc(n/2, sr+n/2, sc,r,c); //3
	boardfunc(n/2, sr, sc,sr + (n/2) - 1,sc + (n/2) -1); //1
	boardfunc(n/2, sr, sc+n/2, sr + (n/2) - 1, sc + (n/2)); //2
	boardfunc(n/2, sr+n/2, sc+n/2, sr + (n/2),sc + n/2); // 4*/
	//
	boardfunc(n/2, sr+n/2, sc,sr + n/2,sc+ (n/2) - 1); //3
	boardfunc(n/2, sr, sc,r,c); //1
	boardfunc(n/2, sr, sc+n/2, sr + (n/2) -1, sc + (n/2)); //2
	boardfunc(n/2, sr+n/2, sc+n/2, sr + (n/2),sc + n/2); // 4



}

int main()
{
	int n,row,col;
	cout<<"Enter board size (n): "<<endl;
	cin>>n;
	cout<<"Enter Row of blank space (row): "<<endl;
	cin>>row;
	cout<<"Enter Column of black space (col): "<<endl;
	cin>>col;
	create(n,row,col);
	boardfunc(n,0,0,row,col);
	print(n);
	return 0;
}