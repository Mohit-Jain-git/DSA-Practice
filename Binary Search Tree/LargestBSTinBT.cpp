#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *left, *right;
    node(int val)
    { 
       data = val;
       left=NULL;
       right=NULL;
    }
};
struct info{
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};
info largestBST(node *root)
{ 
    if(root==NULL)
    return {0,INT_MIN,INT_MAX,0,true};
    if(root->left==NULL && root->right==NULL)
    return {1,root->data,root->data,1,true};

    info leftInfo = largestBST(root->left);
    info rightInfo = largestBST(root->right);

    info curr;
    curr.size = (1 + leftInfo.size + rightInfo.size);

    if(leftInfo.isBST && rightInfo.isBST && leftInfo.max<root->data && rightInfo.min>root->data){ 
        curr.min = min(leftInfo.min,min(rightInfo.min,root->data));
        curr.max = max(rightInfo.max,max(leftInfo.max,root->data));
        
        curr.ans = curr.size;
        curr.isBST = true;
        return curr;
    }
    curr.ans = max(leftInfo.ans, rightInfo.ans);
    curr.isBST = false;
    return curr;
}
int main()
{ 
    node *root = new node(4);
    root->left = new node(2);
    root->right = new node(5);
    root->left->left = new node(1);
    root->left->right = new node(3);
    root->right->right = new node(6);
    cout<<"Largest BST in BT : "<<largestBST(root).ans<<endl;
    return 0;

}