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
void bottomview(node *root)
{ 
   map<int,int> m;
   queue<pair<node*,int>> q;
   if(root==NULL)
   return;
   q.push({root,0});
   while(!q.empty())
   { 
       node *t = q.front().first;
       int h = q.front().second;
       q.pop();
       m[h] = t->data;
       if(t->left)
       q.push({t->left,h-1});
       if(t->right)
       q.push({t->right,h+1});
   }
     for(auto x:m)
     cout<<x.second<<" ";
}
int main()
{
  node *root = new node(1);
  root->left = new node(2);
  root->right = new node(3);
  root->left->left = new node(4);
  root->left->right = new node(5);
  root->right->left = new node(6);
  root->right->right = new node(7);
  bottomview(root);

  return 0;
}