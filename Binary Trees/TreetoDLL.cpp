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
void solve(node* root,node* &head,node* &prev,int &f)
{ 
    if(root==NULL)
    return;
    solve(root->left,head,prev,f);
    if(f==0)
    { 
       f = 1;
       head = root;
       prev = root;
    }
    else
    { 
       prev->right = root;
       prev->right->left = prev;
       prev = prev->right;
    }
    solve(root->right,head,prev,f);
}
node * btoDll(node *root)
{ 
   node *head = NULL;
   node *prev = NULL;
   int f = 0;
   solve(root,head,prev,f);
   return head;
}
void print(node *root)
{ 
   while(root!=NULL)
   { 
      cout<<root->data<<" ";
      root = root->right;
   }
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
  node *head = btoDll(root);
  print(head);
  return 0;
}