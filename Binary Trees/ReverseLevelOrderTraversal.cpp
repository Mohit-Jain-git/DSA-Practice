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
void reverseprintLevelOrder(node *root)
{
    if(root==NULL)
    return;
    vector<int> ans;
    queue<node*> q;
    q.push(root);
    while(q.empty()!=1)
    { 
       node *s= q.front();
       ans.push_back(s->data);
       q.pop();
       if(s->right)
       q.push(s->right);
       if(s->left)
       q.push(s->left);
    }
     reverse(ans.begin(),ans.end());
     for(int i=0;i<ans.size();i++)
     cout<<ans[i]<<" ";
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
  reverseprintLevelOrder(root);
  return 0;
}