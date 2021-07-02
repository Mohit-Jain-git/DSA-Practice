#include<bits/stdc++.h>
using namespace std;
int main()
{ 
   int n,m,i,j;
   unordered_map<int,int> map;
   cin>>n>>m;
   int a[n],b[m];
   for(i=0;i<n;i++)
   {
   cin>>a[i];
   map[a[i]]++;
   }
   for(j=0;j<m;j++)
   {
   cin>>b[j];
   map[b[j]]++;
   }
   cout<<map.size();
   return 0;
}