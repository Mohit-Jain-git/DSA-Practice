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
int f=1;
int solve(node *root)
{   
    if(root==NULL)
    return 0;
    if(root->left==NULL and root->right==NULL)
    return root->data;
    if(f==0)
    return f;
    int a = solve(root->left);
    int b = solve(root->right);
    if((a+b)!=root->data)
    f=0;
    return a+b+root->data;
}
bool isSumTree(node *root)
{ 
    f=1;
    solve(root);
    return f;
}
int main()
{
  struct node *root = new node(3);
  root->left = new node(1);
  // root->left->left = new node(4);
  // root->left->right = new node(5);
  root->right = new node(2);
  // root->right->left = new node(6);
  // root->right->right = new node(7);
  bool i = isSumTree(root);
  cout<<i;
  return 0;
}