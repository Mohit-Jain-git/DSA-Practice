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
node *LCA(node *root, int n1, int n2)
{
  if (root == NULL)
    return NULL;
  if (root->data == n1 || root->data == n2)
    return root;
  node *lLCA = LCA(root->left, n1, n2);
  node *rLCA = LCA(root->right, n1, n2);
  if (lLCA && rLCA)
    return root;
  if (lLCA != NULL)
    return lLCA;
  return rLCA;
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
  int n1 = 4;
  int n2 = 7;
  node *lca = LCA(root, n1, n2);
  if (lca == NULL)
    cout << "Root doesn't exist"
         << " ";
  else
    cout << "LCA is: " << lca->data << " ";
  return 0;
}
