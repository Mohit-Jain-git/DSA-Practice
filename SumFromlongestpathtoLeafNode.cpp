#include <bits/stdc++.h>
using namespace std;
struct node
{
  int data;
  struct node *left;
  struct node *right;
  node(int val)
  {
    data = val;
    left = NULL;
    right = NULL;
  }
};
int sumofLongroottoLeafPath(node *root,int sum,int len,int &maxsum,int &maxlen)
{ 
    if(root==NULL)
    return 0;
    else
    {
       if(maxlen<len && maxsum<sum)
       { 
          maxlen = len;
          maxsum = sum;
       }
       else if(maxlen==len && maxsum<sum)
       { 
           maxsum = sum;
       }
       return maxsum; 
    }
       
       sumofLongroottoLeafPath(root->left,sum+root->data,len+1,maxsum,maxlen);
       sumofLongroottoLeafPath(root->right,sum+root->data,len+1,maxsum,maxlen);
}
int main()
{
  struct node *root = new node(1);
  root->left = new node(2);
  root->right = new node(3);
  root->left->left = new node(4);
  root->left->right = new node(5);
  root->right->left = new node(6);
  root->right->right = new node(7);
  int maxsum = INT_MIN, maxlen=0;
  cout<<"Sum :"<<sumofLongroottoLeafPath(root,0,0,maxsum,maxlen);
  return 0;
}