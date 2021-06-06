#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node
{ 
   int data;
   struct node *left;
   struct node *right;
   node(int val)
   { 
      data = val;
      left=NULL;
      right=NULL;
   }
};
void getVerticalOrder(node *root,int hi,map <int,vector<int>> &m)
{ 
    if(root==NULL)
    return;
    m[hi].push_back(root->data);
    getVerticalOrder(root->left,hi-1,m);
    getVerticalOrder(root->right,hi+1,m);
}
int main()
{ 
   node *root = new node(10);
   root->left = new node(7);
   root->right = new node(4);
   root->left->left = new node(3);
   root->left->right = new node(11);
   root->right->left = new node(14);
   root->right->right = new node(6);
   
    map <int,vector<int>> m;
    int hi = 0;
    getVerticalOrder(root,hi,m);
    map<int,vector<int>> :: iterator it;
    for(it=m.begin() ; it!=m.end(); it++)
    { 
       for(int i=0;i<it->second.size(); i++)
       { 
         cout<<it->second[i]<<" ";
       }
       cout<<endl;
    } 
    return 0;
}