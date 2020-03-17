/*
                    Description;
    My algo first takes input from file and stores the location preference of each team against its number
    Only 1 2D array of n x 2n dimensions is used.
    First i take the last location of a team and assign it as its final destination. When the collision 
    occurs then i check in the team's prefernce list that which team should be given that location. the team with
    least index number for that location gets that location. - also occupy 1 index........... So on for every location

    Time complexity - > O(n^2)
    Space complexity -> O(n^2)
*/



#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include <string.h>
#include <sstream>
#include <vector>
using namespace std;

bool planepref(int **hangar, int p, int a, int a1, int n) 
{ 
	int col = (2*n) +1;
    // Check if Plane prefers hangar "a" over current hangar "a1" .  
    for (int i = 1; i <col ; i++) 
    { 
        // If a1 comes before a in list of plane, then plane prefers  
        // cirrent hangar, don't do anything 
        if (hangar[a][i] == p) 
            return false; 
  
        // If "a" comes before "a1" in plane's list, then free current 
        // hangar and place it in hangar "a" 
        if (hangar[a1][i] == p) 
           return true; 
    } 
} 



// Prints stable matching for N boys and N girls. Boys are numbered as 0 to 
// N-1. Girls are numbereed as N to 2N-1. 
void matching(int **teams, int n) 
{ 
    // Stores plane at a hangar. This is our output array that 
    // stores paing information.  The value of locations[i] 
    // indicates the hangar assigned to plane i.
    int locations[n]; 
    int w;
    int rc = (2*n) +1;
    int temp,temp2;
  
    // An array to store availability of planes.  If free_team[i] is 
    // false, then plane 'i' is free, otherwise not. 
    bool free_team[n]; 
  
    // Initialize all planes and hangars as free 
    memset(locations, -1, sizeof(locations)); 
    memset(free_team, false, sizeof(free_team)); 
    int freeCount = n; 
  
    // While there are free plane 
    while (freeCount > 0) 
    { 
        // Pick the first free team (we could pick any) 
        int m; 
        for (m = 0; m < n; m++) 
            if (free_team[m] == false) 
                break; 
  
        // One by one go to all hangar according to m's preferences. 
        // Here m is the picked free man 
        for (int i = 1; i < rc;i++) 
        { 
        	
        	if(teams[m][i] != -1)
             {
             	w = teams[m][i];
               // cout<<teams[m][i];
             	//cout<<"last loc: "<<w<<endl;	
             } 
            else
            {
            	continue;
            }
        }
        //cout<<"loc "<<w<<endl;
       // for (int i = 1; i < rc && free_team[m] == false; i++) 
      //  { 
           // int w = teams[m][i]; 
            
  
            // The hangar of preference is free, w and m become 
            // partners (Note that the partnership maybe changed 
            // later). 
            if (locations[w] == -1) 
            { 
                locations[w] = m; 
                free_team[m] = true; 
                freeCount--; 
            } 
  
            else  // If w is not free 
            { 
                // Find current engagement of w 
                int m1 = locations[w]; 
  
                // If w prefers m over her current engagement m1, 
                // then break the engagement between w and m1 and 
                // engage m with w. 
                if (planepref(teams, w, m, m1,n) == false) 
                { 
                    //cout<<"falsee"<<endl;
                    locations[w] = m; 
                    free_team[m] = true; 
                    free_team[m1] = false; 
                    for(int i=0;i<rc;i++)
                    {
                        if(teams[m1][i]== w)
                            teams[m1][i] = -1;
                    }
                    
                } 
                if (planepref(teams, w, m, m1,n) == true) 
                { 
                    for(int i=0;i<rc;i++)
                    {
                        if(teams[m][i]== w)
                            teams[m][i] = -1;
                    }
                } 
            } // End of Else 
        //} // End of the for loop that goes to all women in m's list 
    } // End of main while loop 
  
  for (int i = 0; i < n; i++)
  	locations[i] = locations[i] + 1;
    // Print the solution 
    //cout << "Location       Team" << endl; 
  cout<<"Final Destinations: "<<endl;
    for (int i = 0; i < n; i++) 
       {
        cout <<"T" <<locations[i]<<" "<<"L" << i+1;
        if(i < n-1 )
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
    //cout<<"N is "<<n<<endl;
    int reqcolumns = 2*n+1;
    int **teams;
    teams = new int* [n];
    /*vector<vector<int> > dest;*/
    for(int i=0;i<n;i++)
    {
    	teams[i] = new int [reqcolumns];
    }
    for(int i=0;i<n;i++)
    {
    	teams[i][0] = i;
    }
    int p_r =0;
    int p_c=1;
    while(getline(infile,input))
    {
        istringstream st(input);
        string sample;
        int found;
        if(input[0] == 'T')
       {
        while(st >> sample)
        {
         
         if(sample[out] == 'L')
            {
                char lol = sample[out + 1];
                found = lol - '0';
                teams[p_r][p_c] = found - 1;
                //cout<<teams[p_r][p_c]<<"  ";
                p_c++;
                continue;
                //cout<<found<<endl;
              
            }
            if(sample[out] == '-')
            {
                teams[p_r][p_c] = -1;
                //cout<<teams[p_r][p_c]<<"  ";
                p_c++;
                continue;
                //cout<<found<<endl;
              
            }
    
         
        }
        p_r++;
        p_c=1;
        //cout<<endl;
   	   }
   

}
/*for(int i=0;i<n;i++)
{
    dest[i].push_back(i);
}*/
/*for(int i=0;i<n;i++)
{
	for(int j =0;j<reqcolumns;j++)
	{
		cout<<teams[i][j]<<"    ";
	}
	cout<<endl;
}*/
matching(teams,n);
}


int main()
{
	Input_file("new2.txt");
	return 0;
}