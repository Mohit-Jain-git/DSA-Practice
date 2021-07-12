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
int SumTree(node* root)
{ 
   if(root == NULL)
   return 0;
   int a = SumTree(root->left);
   int b = SumTree(root->right);
   int x = root->data;
   root->data = a + b;
   return a + b + x;
}
void inorder(node *root)
{ 
    if(root == NULL)
    return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
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
  SumTree(root);
  inorder(root);
  return 0;
}