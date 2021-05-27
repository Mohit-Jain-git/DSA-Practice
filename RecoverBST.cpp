#include<iostream>
using namespace std;
struct node { 
   int data;
   struct node *left,*right;
   node(int val)
   { 
       data = val;
       left=NULL;
       right=NULL;
   }
};
void swap(int *a,int *b)
{ 
    int temp = *a;
    *a = *b;
    *b = temp;
}
void calcpointers(node *root,node **first,node **last,node **mid,node **prev)
{ 
    if(root==NULL)
    return;
    calcpointers(root->left ,first ,last ,mid, prev);
    if(*prev &&  root->data < (*prev)->data ) 
    { 
        if(!*first)
        { 
            *first = *prev;
            *mid = root;
        }
        else
        { 
            *last = root;
        }
    }
    *prev = root;
    calcpointers(root->right,first,last,mid,prev);
}
void recoverBST(node *root)
{ 
    struct node* first, *last, *mid, *prev;
    first=NULL;
    last=NULL;
    mid=NULL;
    prev=NULL;

    calcpointers(root, &first ,&last ,&mid ,&prev);
    if(first && last)
    swap(&(first->data),&(last->data));
    else if(first && mid)
    swap(&(first->data),&(mid->data));
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
    node *root = new node(6);
    root->left = new node(9);
    root->right = new node(3);
    root->left->left = new node(1);
    root->left->right = new node(4);
    root->right->right = new node(13);
    inorder(root);
    cout<<endl;
    recoverBST(root);
    inorder(root);
    cout<<endl;
    return 0;
}