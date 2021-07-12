#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    { 
      int count=1;
       for(int j=i;j<=n;j++)
       { 
          cout<<count<<" ";
          count++;
       }
       cout<<endl;
    } 
    return 0;
}