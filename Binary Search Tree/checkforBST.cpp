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
bool isBST(node *root, node *min, node *max)
{
  if (root == NULL)
    return true;
  if (min != NULL && root->data <= min->data)
    return false;
  if (max != NULL && root->data >= max->data)
    return false;
  bool leftValid = isBST(root->left, min, root);
  bool rightValid = isBST(root->right, root, max);
  return leftValid and rightValid;
}
int main()
{
  node *root = new node(4);
  root->left = new node(2);
  root->right = new node(5);
  root->left->left = new node(1);
  root->left->right = new node(3);
  root->right->right = new node(6);
  if (isBST(root, NULL, NULL))
    cout << "Valid BST";
  else
    cout << "Invalid BST";
  return 0;
}