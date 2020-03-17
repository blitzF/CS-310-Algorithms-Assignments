/*
    Description:
    Recurrence relation : T(n) = T(n/2) + 1
    ALgo;
  First i converted the given array into binary tree. Then i found all the leaves of the tree.
  Then i stored the ancestors of every leaf in a 2d vector. After that i found the maximum ancestry 
  by calculating the maximum sum of a leaf and its ancestry. In this way i chose two value xi and xj i.e
  indexes for the leaves that give maximum ancestry.
  After that i printed their ancestry and printed the max ancestry.
  Space complexity -> O(n^2)
  Time complexity -> O(nlogn)


*/
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h> 
#include <vector>
using namespace std;

struct Node
{
	int value;
	Node *left;
	Node *right;
};


Node *newNode(int key) 
{ 
    Node *temp = new Node; 
    temp->value  = key; 
    temp->left  = temp->right = NULL; 
    return (temp); 
}

int height(struct Node* node) 
{ 
    if (node==NULL) 
        return 0; 
    else
    { 
        /* compute the height of each subtree */
        int lheight = height(node->left); 
        int rheight = height(node->right); 
  
        /* use the larger one */
        if (lheight > rheight) 
            return(lheight+1); 
        else return(rheight+1); 
    } 
}

void findsum(int arr[], vector<vector <int> > a, int size, int &x1, int &x2)
{
	int j =0;
	while(j<size)
	{
		for(int i=0; i<a[j].size();i++)
		{
			arr[j] = arr[j] + a[j][i];
		}
		j++;
	}
		int largest = arr[0];
        for (int i = 1; i < size; i++) 
        {
		if (largest < arr[i])

			{largest = arr[i];
			x1 = i;}
		}
		int largest2 = -1;
		for (int i = 0; i < size; i++) 
        {
		if (largest2 < arr[i] && arr[i] != largest)

			{largest2 = arr[i];
			x2 = i;}
		}
		//cout<<largest<<"  "<<largest2<<endl;
		//cout<<a[4][0]<<"  "<<a[2][0]<<endl;

}  

bool printAncestors(struct Node *root, int target , vector <int> &anc, int i) 
{ 
  /* base cases */
  if (root == NULL) 
     return false; 
  
  if (root->value == target)
  {
  	//cout<<target<<" ";
  	anc.push_back(target);
     return true; 
  }
  
  /* If target is present in either left or right subtree of this node, 
     then print this node */
  if ( printAncestors(root->left, target,anc,i) || 
       printAncestors(root->right, target,anc,i) ) 
  { 
    //cout << root->value << " ";
    anc.push_back(root->value); 
    return true; 
  } 
  
  /* Else return false */
  return false; 
} 

void LeafNodes(Node *root, vector<int>& leafs) 
{ 
    // if node is null, return 
    if (!root) 
        return ; 
      
    // if node is leaf node, print its data     
    if (!root->left && !root->right) 
    { 	
    	leafs.push_back(root->value);
        //cout << root->value << " "; 
        //i++; 
        return; 
    } 
  
    // if left child exists, check for leaf  
    // recursively 
    if (root->left) 
       LeafNodes(root->left,leafs); 
          
    // if right child exists, check for leaf  
    // recursively 
    if (root->right) 
       LeafNodes(root->right,leafs); 
}  


Node* ins(int arr[], Node* root, 
                       int i, int n) 
{ 
    // Base case for recursion 
    if (i < n) 
    { 
        Node* temp = newNode(arr[i]); 
        root = temp; 
  
        // insert left child 
        root->left = ins(arr, 
                   root->left, 2 * i + 1, n); 
  
        // insert right child 
        root->right = ins(arr, 
                  root->right, 2 * i + 2, n); 
    } 
    return root; 
} 

void printer(vector<vector<int> > a, int x1, int x2) 
{ 
	int fin = 0;
	cout <<"xi = "<<a[x1][0]<<endl;
	cout <<"xj = "<<a[x2][0]<<endl;
    cout<<"Ancestry of "<<a[x1][0]<<" :"<<endl;
    for(int i=0; i<a[x1].size();i++)
    	cout<<a[x1][i]<<" ";
    cout<<endl;
    cout<<"Ancestry of "<<a[x2][0]<<" :"<<endl;
    for(int i=0; i<a[x2].size();i++)
    	cout<<a[x2][i]<<" ";
    cout<<endl;
    cout<<"MAX ANCESTRY:  ";
    for(int i=0;i<a[x1].size();i++)
    {
    	if(a[x1][i] != a[x2][i])
    	{
    		fin = fin+a[x1][i] + a[x2][i];
    		//cout<<fin<<endl;
    	}
    	else
    	{
    		fin = fin+a[x1][i];
    	}
    }
    cout<<fin<<endl; 
} 


int main()
{
	int n = 15;
	int xi,xj;
	int tree[n] =  {17,20,4,5,7,35,6,3,6,16,12,18,1,2,3};
	//int tree[n] = {29, 6, 11, 15, 5, 10, 20, 1, 3, 4, 2, 15, 45, 10, 50};
	Node *t = ins(tree, t, 0, n);
	/*cout<<"Enter the value of xi  "; cin>>xi;
	cout<<"Enter the value of xj  "; cin>>xj;*/
	cout<<endl;
	int h = height(t);
	int leafnum = pow(2,h-1);
	vector<int> leafs;
	LeafNodes(t,leafs); // gives leaf nodes
	vector<int> ancest[leafs.size()];
	vector<vector <int> > ancesto;
	for(int i =0; i < leafs.size(); i++) 
		printAncestors(t,leafs[i],ancest[i],i);
	for(int i=0;i<leafs.size();i++)
		ancesto.push_back(ancest[i]);
	int ms[leafs.size()] = {0};
	findsum(ms,ancesto,leafs.size(),xi,xj);
	printer(ancesto,xi,xj);
	return 0;
}