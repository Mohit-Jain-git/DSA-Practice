#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *left,*right;
    node(int val)
    { 
       data = val;
       left=NULL;
       right=NULL;
    }
};
node* sortedArraytoBST(int arr[],int start,int end)
{ 
     if(start>end)
     return NULL;
     int mid = (start+end)/2;
     node *root = new node(arr[mid]);
     root->left = sortedArraytoBST(arr,start,mid-1);
     root->right = sortedArraytoBST(arr,mid+1,end);
     return root;
}
void preorder(node *root)
{ 
     if(root==NULL)
     return;
     cout<<root->data<<" ";
     preorder(root->left);
     preorder(root->right);
}
void inorder(node *root)
{ 
     if(root==NULL)
     return;
     inorder(root->left);
     cout<<root->data<<" ";
     inorder(root->right);
}
int main()
{ 
     int arr[100],n;
     cin>>n;
     for(int i=0;i<n;i++)
     cin>>arr[i];
     node*root = sortedArraytoBST(arr,0,n-1);
     preorder(root);
     cout<<endl;
     inorder(root);
     cout<<endl;
     return 0;
}