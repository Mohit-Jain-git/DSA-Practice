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
bool isbalance(node *root, int *height)
{
  int lh = 0, rh = 0;
  if (root == NULL)
    return true;
  if (isbalance(root->left, &lh) == false)
    return false;
  if (isbalance(root->right, &rh) == false)
    return false;
  *height = max(lh, rh) + 1;
  if (abs(lh - rh) <= 1)
    return true;
  else
    return false;
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
  int height = 0;
  if (isbalance(root, &height))
    cout << "Balance Tree" << endl;
  else
    cout << "Unbalance Tree" << endl;
  return 0;
}