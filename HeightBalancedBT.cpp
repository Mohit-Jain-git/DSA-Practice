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
int height(node *root)
{
  if (root == NULL)
    return -1;
  return max(height(root->left), height(root->right)) + 1;
}
bool isBalanced(node *root)
{
  if (root == NULL)
    return true;
  if (isBalanced(root->left) == false)
    return false;
  if (isBalanced(root->right) == false)
    return false;
  int lheight = height(root->left);
  int rheight = height(root->right);
  if (abs(lheight - rheight) <= 1)
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
  if (isBalanced(root))
    cout << "Balanced Tree" << endl;
  else
    cout << "Unbalanced Tree" << endl;
  return 0;
}