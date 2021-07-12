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
node *searchinBST(node *root, int key)
{
  if (root == NULL)
    return NULL;
  if (root->data == key)
    return root;
  if (root->data > key)
    return searchinBST(root->left, key);
  else
    return searchinBST(root->right, key);
}
int main()
{
  node *root = new node(4);
  root->left = new node(2);
  root->right = new node(5);
  root->left->left = new node(1);
  root->left->right = new node(3);
  root->right->right = new node(6);
  if (searchinBST(root, 10) == NULL)
    cout << "Key doesn't exist.";
  else
    cout << "Key exist.";
  return 0;
}