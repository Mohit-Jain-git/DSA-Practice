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
void printLevelOrder(node *root)
{
  if (root == NULL)
    return;
  queue<node *> q;
  q.push(root);
  // q.push(NULL);
  while (q.empty() != 1)
  {
    node *Node = q.front();
    q.pop();
      cout << Node->data << " ";
      if (Node->left)
        q.push(Node->left);
      if (Node->right)
        q.push(Node->right);
     }
    // else if (q.empty() != 1)
      // q.push(NULL);
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
  printLevelOrder(root);

  return 0;
}