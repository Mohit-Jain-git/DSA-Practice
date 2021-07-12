#include<bits/stdc++.h>
using namespace std;
int main()
{ 
    int n,flag=0;
    cin>>n;
    if(n==1 || n==0)
    cout<<"Not Prime";
    else
    { 
       for(int i=2;i<n/2;i++)
       { 
          if(n%i==0)
          { 
             flag=1;
             break;
          }
       }
       if(flag==1)
       cout<<"Not Prime";
       else
       cout<<"Prime";
    }
    return 0;
}