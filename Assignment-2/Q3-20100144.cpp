/*
//Data Structures Used//
1) nxn Array to form the board. (initialized to 0)
2) Two priority queues i.e. one for the rows and one for columns
3) struct to store postion i.e index and value at that index.
//Algo Description//
First of all I pushed rows in priority queue giving the highest priority to the row containing highest value i.e. the row that contains highest number
of the pieces to be placed. After placing all the rows I am placing the columns in the prioity queue in the same manner. And then i start processing 
by taking the top row from queue i.e. the row with highest pieces and select corresponding column. After placing the piece the in the column I minus (-1)
the value of pieces to be placed in that column and then push it in the queue again according to its priority. This way i traverse every column for every row.
By placing a piece i mean changing the value of 2-D Board array from 0 to 1 i.e. Array[row][col] = 1. After that, I just print the sequence of 1's from the
board.
If the placement is not possible i.e some col or row remains unempty then I print "NOT".

//Time and Space Complexity//
Time Complexity of the algo is : O(n^2) - > As per i perceived. Time compelxity of this algo should be O(n^2)
like n(n + n)
Space Complextity of the algo is : O(n^2) -> Using a 2-D array. All other structs are O(n)max.
*/



#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include<fstream>
#include<string>
#include<string.h>
#include<sstream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

struct positions{
int pos, value;
};


struct compare
{
    bool operator() (positions a, positions b)
    {
        return a.value < b.value;
    }
};


    priority_queue<positions , vector<positions>, compare> row_queue;
    priority_queue<positions , vector<positions>, compare> col_queue;
    //Queues to place rows and columns with highest pieces to be placed. (Highest->top)


void board(int n)
{
    int b_array[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            b_array[i][j] = 0;
            //Initialized to 0 (Board)
        }
    }

   // cout <<

    while(!row_queue.empty())
    {
        positions row_top = row_queue.top();
        //gives the row with highest pieces to be placed
        vector<positions> store;
        // temporary vector of structs to store columns that are being poped from queue after placing 1 piece at that index.
        //storing the column in this vector to push them back in the priority queue.
        for(int i = 0; i < row_top.value; i++)
        {
            positions temp = col_queue.top();
            //gives column with highest number 
        //    cout << "row =" << row_top.pos << "    temp.pos" << temp.pos << "    temp.value" << temp.value << endl;
            b_array[row_top.pos][temp.pos] = 1;
            temp.value--;
            //one piece is placed in that column
            col_queue.pop();
            //column is removed
            if(temp.value != 0)
                store.push_back(temp);
            //store in temporary vector
        }
        for(int i= 0; i < store.size(); i++)
        {
            col_queue.push(store[i]);
            // pushed back the column from vector into queue
        }
        row_queue.pop();
        //After placing all the pieces in the row. row is removed.
    }

    if(!col_queue.empty() || !row_queue.empty())
    {
                    cout << "Not" << endl;
                    return;
    }

    else
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(b_array[i][j] == 1)
                    cout << "(" << i+1 << ", " << j+1 << ")" << "    ";
                //prints the indices combination with pieces.
                //adding 1 becuase indices start from 0.

            }
            cout<<endl;
        }
    }

}



void Input_file(string name)
{
    ifstream infile;
    string input,garbage;
    int n;
    infile.open(name.c_str());
    infile>>garbage>>n;

//    positions* arr = new positions[n];
    //cout<<n<<endl;



    int i = 0,j = 0;

    while(getline(infile,input))
    {
        istringstream st(input);
        string sample;
        int found;
        while(st >> sample)
        {
            positions temp;
            if(sample == "Col")
            {
                //cout<<endl;
                while(j < n)
                {
                    st >>sample;
                if(stringstream(sample) >> found)
                    {
                        temp.pos = j;
                        temp.value = found;
                        col_queue.push(temp);
                        //cout<<col_queue.value << endl;

                        j++;
                    //cout<<"value of H is: "<<found<<endl;
                    }
                }

               // break;
            }
            else
         {
             if(stringstream(sample) >> found)
            {
                temp.pos = i;
                temp.value = found;
                row_queue.push(temp);
                //cout<<"found is "<<found<<endl;
                //cout<<rows[i];
                i++;
            }
        }
        }
       // cout<<endl;

    }

 //   while(!row_queue.empty() && !col_queue.empty()) {
  //      cout << "row = " << row_queue.top().pos << "\t" << row_queue.top().value << endl;
  //      cout << "col = " <<col_queue.top().pos << "\t" << col_queue.top().value << endl;
  //      row_queue.pop();
  //      col_queue.pop();
  //  }
    board(n);


}


int main()
{
    Input_file("Q3test1.txt");
    return 0;
}
