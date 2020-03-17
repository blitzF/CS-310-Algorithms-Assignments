/*
                Description
My algo works on gale sharpely matching method. It first takes a free aeroplane and assigns its first
preferred airport or hangar. And then goes on. And when the collision occurs regarding a hangar
it checks in the list of hangar that which plane is of higher importance.
Time complexity -> O(n^2)
Space Complexity -> O(n^2)
I used two 2d arrays for storing preferences of planes and hangars.
*/




#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include<fstream>
#include<string>
#include<string.h>
#include<sstream>
using namespace std;

bool planepref(int **hangar, int p, int a, int a1, int n) 
{ 
    // Check if Plane prefers hangar "a" over current hangar "a1" .  
    for (int i = 1; i < n+1; i++) 
    { 
        // If a1 comes before a in list of plane, then plane prefers  
        // cirrent hangar, don't do anything 
        if (hangar[p][i] == a1) 
            return true; 
  
        // If "a" comes before "a1" in plane's list, then free current 
        // hangar and place it in hangar "a" 
        if (hangar[p][i] == a) 
           return false; 
    } 
} 



// Prints stable matching for N boys and N girls. Boys are numbered as 0 to 
// N-1. Girls are numbereed as N to 2N-1. 
void matching(int **plane, int **hangar,int **nothangar, int n) 
{ 
    // Stores plane at a hangar. This is our output array that 
    // stores paing information.  The value of hangars_array[i] 
    // indicates the hangar assigned to plane i.
    int hangars_array[n]; 
  
    // An array to store availability of planes.  If free_plane[i] is 
    // false, then plane 'i' is free, otherwise not. 
    bool free_plane[n]; 
  
    // Initialize all planes and hangars as free 
    memset(hangars_array, -1, sizeof(hangars_array)); 
    memset(free_plane, false, sizeof(free_plane)); 
    int freeCount = n; 
  
    // While there are free plane 
    while (freeCount > 0) 
    { 
        // Pick the first free plane (we could pick any) 
        int m,w; 
        for (m = 0; m < n; m++) 
            if (free_plane[m] == false) 
                break; 
  
        // One by one go to all hangar according to m's preferences. 
        // Here m is the picked free man 
        for (int i = 1; i < n && free_plane[m] == false; i++) 
        { 
            if(nothangar[m][1] != plane[m][i])
            {

                
                w = plane[m][i];
            } 
            else 
            {
                continue;
            }
            
            // The hangar of preference is free, w and m become 
            // partners (Note that the partnership maybe changed 
            // later). 
            if (hangars_array[w] == -1 ) 
            { 
                //if(nothangar[m][1] != w)
                //{
               // cout<<"Here"<<w<<m<<endl;
                hangars_array[w] = m; 
                free_plane[m] = true; 
                freeCount--;
                //} 
                //else 
                //  continue;
            } 
  
            else  // If w is not free 
            { 
                // Find current engagement of w 
                int m1 = hangars_array[w]; 
  
                // If w prefers m over her current engagement m1, 
                // then break the engagement between w and m1 and 
                // engage m with w. 
                if (planepref(hangar, w, m, m1,n) == false) 
                { 
                    
                    hangars_array[w] = m; 
                    free_plane[m] = true; 
                    free_plane[m1] = false;
                  
                }
                
            } // End of Else 
        } // End of the for loop that goes to all women in m's list 
    } // End of main while loop 
  
  for (int i = 0; i < n; i++)
  	hangars_array[i] = hangars_array[i] + 1;
    // Print the solution 
    //cout << "Plane   Hangar" << endl; 
  cout<<"Stable Matching: "<<endl;
    for (int i = 0; i < n; i++) 
       {
        cout <<"A" <<i+1 <<" P" <<hangars_array[i];
        if(i < n-1)
            cout<<", ";
       } 
} 


void Input_file(string name)
{
    ifstream infile;
    string input,garbage;
    int n;
    int out = 0 ;
    infile.open(name.c_str());
    infile>>garbage>>n;
    cout<<"N is "<<n<<endl;
    //int plane[n][5];
    //int hangar[n][5];
    int **plane;
    int **hangar;
    int **nothangar;
    plane = new int* [n];
    hangar = new int* [n];
    nothangar = new int* [n];
    for(int i=0;i<n;i++)
    {
    	plane[i] = new int [n+1];
    	hangar[i] = new int [n+1];
    	nothangar[i] = new int [2];
    }
    int p_r =0;
    int p_c=1;
    int a_r=0,a_c=1;
   for(int i=0;i<n;i++)
    {
    	plane[i][0] = i;
    	hangar[i][0] = i;
    	nothangar[i][0] = i;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<2;j++)
        {
            nothangar[i][j] = -1;
        }
        
    }
    while(getline(infile,input))
    {
        istringstream st(input);
        string sample;
        int found;
        if(input[0] == 'P')
       {
       	//p_c = 1;
        while(st >> sample)
        {
         
         if(sample[out] == 'A')
            {
                char lol = sample[out + 1];
                found = lol - '0';
                plane[p_r][p_c] = found - 1;
                //cout<<plane[p_r][p_c]<<"  ";
                p_c++;
                if(p_c >= n+1)
                {
                	p_r++;
                	p_c=1;
                }
                continue;
                //cout<<found<<endl;
              
            }
    
         
        }
   	   }
   	   if(input[0] == 'A')
       {
        while(st >> sample)
        {
         
         if(sample[out] == 'P')
            {
                char lol = sample[out + 1];
                found = lol - '0';
                hangar[a_r][a_c] = found - 1;
                //cout<<hangar[a_r][a_c]<<"  ";
                a_c++;
                if(a_c >= n+1)
                {
                	a_r++;
                	a_c=1;
                }
                continue;
                //cout<<found<<endl;
              
            }
      
         
        }
   	   }



if(input[0] == 'X')
       {
       	int pl,jl;
        while(st >> sample)
        {
         
         if(sample[out] == 'P')
            {
                char lol = sample[out + 1];
                found = lol - '0';    
               // cout<<found<<endl;
                pl=found-1;
              
            }
          if(sample[out] == 'A')
          {
          		char lol = sample[out + 1];
                found = lol - '0';
                //cout<<found<<endl;
                jl=found-1;    
                nothangar[pl][1] = jl;
               // cout<<pl<<"   "<<nothangar[pl][1]<<endl;
          }
      
         
        }
   	   }
        
    }
   
//cout<<a_r<<"  "<<p_r<<endl;
//cout<<a_c<<" "<<p_c<<endl;
matching(plane,hangar,nothangar,n);
    /*for(int i=0;i<n;i++)
    {
    	for(int j=0;j<2;j++)
    	{
    		cout<<nothangar[i][j]<<endl;
    	}
    	cout<<endl;
    }
*/}


int main()
{
	Input_file("new.txt");
	return 0;
}