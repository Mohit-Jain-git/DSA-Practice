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
void LeftTree(node *root,vector<int> &ans)
{ 
    if(root==NULL)
    return;
    if(root->left)
    { 
       ans.push_back(root->data);
       LeftTree(root->left,ans);
    }
    else if(root->right)
    { 
       ans.push_back(root->data);
       LeftTree(root->right,ans);
    }
}
void Leaf(node *root,vector<int> &ans)
{ 
   if(root==NULL)
   return;
   Leaf(root->left,ans);
   if(root->left==NULL && root->right==NULL)
   ans.push_back(root->data);
   Leaf(root->right,ans);
}
void RightTree(node *root,vector<int> &ans)
{ 
    if(root==NULL)
    return;
    if(root->right)
    { 
       RightTree(root->right,ans);
       ans.push_back(root->data);       
    }
    else if(root->left)
    { 
       RightTree(root->left,ans);
       ans.push_back(root->data);
    }
}
void BoundaryTraversal(node *root)
{ 
    if(root==NULL)
    return;
    vector<int> ans;
    ans.push_back(root->data);
    LeftTree(root->left,ans);
    Leaf(root,ans);
    RightTree(root->right,ans);
    for(auto x : ans)
     cout<<x<<" ";  
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
  BoundaryTraversal(root);
  return 0;
}