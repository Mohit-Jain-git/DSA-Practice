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
int findMaxPath(node *root, int &ans)
{
  if (root == NULL)
    return 0;
  int left = findMaxPath(root->left, ans);
  int right = findMaxPath(root->right, ans);
  int nodeMax = max(max(root->data, root->data + left + right),
                    max(root->data + left, root->data + right));
  ans = max(ans, nodeMax);
  int singlePathSum = max(root->data, max(root->data + left, root->data + right));
  return singlePathSum;
}
int MaxPathSum(node *root)
{
  int ans = INT_MIN;
  findMaxPath(root, ans);
  return ans;
}

int main()
{
  node *root = new node(1);
  root->left = new node(2);
  root->right = new node(3);
  root->left->left = new node(4);
  root->right->right = new node(5);
  //test path sum
  cout << MaxPathSum(root);
  return 0;
}