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
bool getpath(node *root, int key, vector<int> &path)
{
  if (root == NULL)
    return false;
  path.push_back(root->data);
  if (root->data == key)
    return true;
  if (getpath(root->right, key, path) || getpath(root->left, key, path))
    return true;
  path.pop_back();
  return false;
}
int LCA(node *root, int n1, int n2)
{
  vector<int> path1, path2;
  if (!getpath(root, n1, path1) || !getpath(root, n2, path2))
    return -1;
  int pc;
  for (pc = 0; pc < path1.size() && path2.size(); pc++)
  {
    if (path1[pc] != path2[pc])
      break;
  }
  return path1[pc - 1];
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
  int lca = LCA(root, n1, n2);
  if (lca == -1)
    cout << "Root doesn't exist"
         << " ";
  else
    cout << "LCA is: " << lca << " ";
  return 0;
}
