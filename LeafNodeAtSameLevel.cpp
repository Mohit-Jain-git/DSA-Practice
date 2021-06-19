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
int ans;
void solve(node *root,int h,int &ma)
{ 
      if(root==NULL)
      return;
      if(ans==0)
      return;
      if(root->left==NULL && root->right==NULL)
      { 
         if(ma==-1)
         { 
            ma=h;
         }
         else
         { 
            if(h!=ma)
            ans=0;
         }
         return;
      }
      solve(root->left,h+1,ma);
      solve(root->right,h+1,ma);
}
bool check(node *root)
{ 
    int h = 0;
    int ma = -1;
    ans = 1;
    solve(root,h,ma);
    return ans;
}
int main()
{
  struct node *root = new node(1);
  root->left = new node(2);
  root->left->left = new node(4);
  root->left->right = new node(5);
  root->right = new node(3);
  root->right->left = new node(6);
  root->right->right = new node(7);
  bool i = check(root);
  cout<<i;
  return 0;
}