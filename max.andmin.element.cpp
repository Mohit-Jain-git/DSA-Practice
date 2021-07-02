#include<bits/stdc++.h>
using namespace std;
int main()
{ 
   int a[100];
   int n;
   cin>>n;
   int i,min=a[0],max=a[0];
   for(i=0;i<n;i++)
   cin>>a[i];
   for(i=1;i<n;i++)
   { 
      if(a[i]>a[0])
      { 
        min=a[0];
        max=a[i];
      }
      else
      { 
        min=a[i];
        max=a[0];
      }
   }
   cout<<"Max element is : "<<max<<endl;
   cout<<"Min element is : "<<min<<endl;
   return 0;
}