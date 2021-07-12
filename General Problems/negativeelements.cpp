#include<bits/stdc++.h>
using namespace std;
int main()
{ 
   int n;
   cin>>n;
   int a[n];
   int i;
   for(i=0;i<n;i++)
   cin>>a[i];
   int j=0;
   for(i=0;i<n;i++)
   { 
      if(a[i]<0)
      {
        if(i!=j)
        {
        swap(a[i],a[j]);
        j++;
        }
      }
   }
   for(i=0;i<n;i++)
   cout<<a[i]<<" ";
   return 0;
}