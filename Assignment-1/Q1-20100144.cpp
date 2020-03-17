/*

                            ALGO - Description
    I have used vector of vectors to store the chemicals. The vector type is INT because
    I want to take Chemical number i.e 0,1,2,3... as input and then deal with it.
    So, it made file parsing easy and i converted the particular char into int.
    Then i used the algorithm library functions i.e find() to find a particular
    chemical in the reactants list of that chemical.That made my algorithm much efficient.
    Although this was a bipartite graph problem, i did it using algorithm library functions
    and i think it was more handy than maintaining a graph...
    Then i used SETS i.e BOX1 and BOX2 for storing the chemicals which don't react with each other.
    TIME COMPLEXITY :
    find() takes O(n), loop goes for O(n), printing loops go for n x O(BOXSIZE).
    so the time complexity for my overall algorithm is O(n^2).
    SPACE COMPLEXITY:
    Since i am using Vector of vectors, space complexity is also O(n^2).




*/



#include <iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#include<set>
#include<fstream>
#include<string>
#include<string.h>
#include<sstream>

using namespace std;

int main()
{
    int n,value,ops1,ops2,check1,check2;
    int e1=0;
    int e2=0;
    int row = -1;
    int printer = 1;
    int out = 0;
    set<int> box1;
    set<int> box2;
    set<int>::iterator it;
    set<int>::iterator itt;
    string input,garbage;
    ifstream infile;
    infile.open("test.txt");
    infile>>garbage>>input;
    n=stoi(input);
    //cout<<n<<endl;
    vector<vector <int> > Chem(n);
    //for(int i=0;i<n;i++)
    //{
      //  Chem[i].push_back(i);
        //cout<<Chem[i][0]<<endl;
    //}
    while(getline(infile,input))
    {

        //cout<<"input is: " <<input<<endl;
        istringstream st(input);
        string sample;
        while(st >> sample)
        {
           // cout<<"sameple is: "<<sample<<endl;
            if(sample[out] == 'C')
            {
                char lol = sample[out + 1];
                value = lol - '0';
                //cout<<value<<endl;
                //cout<<"row is "<<row<<endl;
                Chem[row].push_back(value);
                //cout<<value;
            }
        }
        row++;
       // cout<<endl;

    }


    //int c=0;
    //int r;
    //int reac;
    //for(int i=0;i<6;i++)
    //{
     //   Chem[i].push_back(i);
      //  cout<<Chem[i][0]<<endl;
    //}
   /* while(c<6)
    {
        cout<<"reactants for: "<<endl;
        cin>>r;
        if(r == -1)
            break;
        while(1)
        {
        cout<<"reactant is: "<<endl;
        cin>>reac;
        if(reac == -1)
        {
            c++;
            break;
        }
        Chem[r].push_back(reac);
        }


    }*/
    //int k = Chem[0].size();
    //cout <<k<<endl;
    /*for(int i=0;i<n;i++)
    {
        int siz = Chem[i].size();
        cout<<"Siz is : "<<siz<<endl;
        for(int j=0;j<siz;j++)
        {
            cout<<Chem[i][j];
        }
        cout<<endl;
    }*/

    box1.insert(0);
    for(int i=0;i<5;i++)
                {
                //for (it = Chem[i+1].begin(); it != Chem[i+1].end(); it++)


               // v=Chem[i].begin();
                //advance(v,1);
                if(find(Chem[i+1].begin(), Chem[i+1].end(), i) != Chem[i+1].end())
                {
                    if(box2.size() < 1)
                    {
                        box2.insert(i+1);
                        continue;
                    }
                 else
                {
                for (it = box2.begin(); it != box2.end(); it++)
                {
                    int it_val = *it;
                   // cout<<"vallllllllll: "<<it_val<<endl;
                    if(it_val == i+1)
                    {
                        box2.insert(i+1);
                        break;
                        //continue;

                    }
                    if(find(Chem[it_val].begin(), Chem[it_val].end(), i+1) != Chem[it_val].end())
                    {
                        box1.insert(i+1);
                        //continue;
                        break;
                    }
                    else
                    {
                        box2.insert(i+1);
                        break;
                    }
                }
                }
                }
                //

                else
                {
               if(box1.size() < 1)
                    {
                        box1.insert(i+1);
                        continue;
                    }
                 else
                {
                for (it = box1.begin(); it != box1.end(); it++)
                {
                    int it_val = *it;
                   // cout<<"vallll else: "<<it_val<<endl;
                    if(it_val == i+1)
                    {
                        box1.insert(i+1);
                        break;
                        //continue;

                    }
                    if(find(Chem[it_val].begin(), Chem[it_val].end(), i+1) != Chem[it_val].end())
                    {
                        box2.insert(i+1);
                        continue;
                        //check thoooookkkkk
                        //cout<<"CYCLE ENCOUNTERED"<<endl;
                        //exit(EXIT_FAILURE);
                    }
                    else
                    {
                        box1.insert(i+1);
                        break;
                    }
                }
                }
                }

                /*
                {
                if(box1.size() < 1)
                    {
                        box1.insert(i+1);
                        continue;
                    }
                 else
                {
                for (it = box1.begin(); it != box1.end(); it++)
                {
                    int it_val = *it;
                    cout<<"vallllllllll: "<<it_val<<endl;
                    if(it_val == i+1)
                    {
                        box1.insert(i+1);
                        continue;

                    }
                    if(find(Chem[it_val].begin(), Chem[it_val].end(), i+1) != Chem[it_val].end())
                    {
                        box2.insert(i+1);
                        continue;
                        //cout<<"lorayyyy"<<endl;
                       // exit(1);
                    }
                    else
                    {
                        box1.insert(i+1);
                        continue;
                    }
                }
                }

                }*/
                }

                int box1size,box2size;
                box1size=box1.size();
                box2size=box2.size();
                //cout<<box1size<<"     "<<box2size<<endl;
                //cout<<endl;

                /*

                set<int>::iterator ch;
                set<int>::iterator chh;
                chh=box1.begin();
                for (ch = box2.begin(); ch != box2.end(); ch++)
                {

                    if(find(box1.begin(), box1.end(), *ch) != box1.end())
                    {
                        cout<<*ch;
                        printer = 0;
                        cout<<"ERORR iii oyeee"<<endl;
                        break;
                    }
                    else
                    {
                        cout<<*chh<<"->";
                        continue;
                    }
                }
                */
                set<int>::iterator it1;
                set<int>::iterator it2;
                int putt =1;
                it1 = box1.begin();
                it2 = box1.begin();
                advance(it2,putt);
                //advance(it2,1);
                while(it1 != box1.end())
                {
                while(it2 != box1.end())
                {
                    if(find(Chem[*it1].begin(), Chem[*it1].end(), *it2) != Chem[*it1].end())
                    {
                        e1 = -1;
                        ops1 = *it2;
                        cout<<"NO"<<endl;
                        printer = 0;
                        check1 = 0;
                        break;

                        //exit(EXIT_FAILURE);
                    }
                    else
                    {
                        it2++;
                    }
                }
                if(check1 == 0) break;
                it2=box1.begin();
                it1++;
                putt++;
                advance(it2,putt);
                }
                //
                int put=1;
                set<int>::iterator it11;
                set<int>::iterator it22;
                it11 = box2.begin();
                it22 = box2.begin();
                advance(it22,put);
                while(it11 != box2.end())
                {
                while(it22 != box2.end())
                {
                    if(find(Chem[*it11].begin(), Chem[*it11].end(), *it22) != Chem[*it11].end())
                    {
                        e2 = -1;
                        ops2 = *it22;
                        cout<<"NO"<<endl;
                        printer = 0;
                        check2 = 0;
                        break;
                        //exit(EXIT_FAILURE);
                    }
                    else
                    {
                        it22++;
                    }
                }
                if(check2 == 0) break;
                it22=box2.begin();
                it11++;
                put++;
                advance(it22,put);
                }





                //
                int advancer=0;
                if(printer)
                {
                cout<<"YES "<<endl;
                cout<<"BOX-1 contains:"<<endl;
                for(it = box1.begin(); it != box1.end(); it++)
                {
                    cout<<"C"<<*it;
                    advancer++;
                    if(advancer != box1size)cout<<"->";
                }
                cout<<endl;
                advancer = 0;
                cout<<"BOX-2 contains:"<<endl;
                for(it = box2.begin(); it != box2.end(); it++)
                {
                    cout<<"C"<<*it;
                    advancer++;
                    if(advancer != box1size)cout<<"->";
                }
                }
                else
                {
                    if(e1 == -1)
                {
                    for(it = box2.begin(); it != box2.end(); it++)
                {
                    cout<<"C"<<*it;
                    advancer++;
                    if(advancer != box1size)cout<<"->";
                }
                for(it = box1.begin(); it != box1.end(); it++)
                {
                    if(find(box1.begin(), box1.end(), ops1) != box1.end())
                    {
                    cout<<"->"<<"C"<<ops1<<endl;
                    cout<<"Cycle Occurs at Chemical: "<<"C"<<ops1<<endl;
                    break;
                    exit(0);
                    }
                    else
                        {
                            cout<<*it;
                        }
                }

                }
                    if(e2 == -1)
                    {
                    for(it = box1.begin(); it != box1.end(); it++)
                {
                    cout<<"C"<<*it;
                    advancer++;
                    if(advancer != box1size)cout<<"->";

                }
                for(it = box2.begin(); it != box2.end(); it++)
                {
                    if(find (box2.begin(), box2.end(), ops2) != box2.end())
                    {
                    cout<<"->"<<"C"<<ops2<<endl;
                    cout<<"Cycle Occurs at Chemical: "<<"C"<<ops2<<endl;
                    break;
                    exit(0);
                    }
                    else
                        {
                            cout<<*it;
                        }
                }


                    }

                }
                //cout<<endl;
                //itt = box1.begin();
                //advance(itt,1);
                //cout<<"itt is:"<<*itt<<endl;




    return 0;
}
