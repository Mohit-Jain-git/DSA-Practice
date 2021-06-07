#include<bits/stdc++.h>
using namespace std;
int main()
{ 
    long long int n;
    cin>>n;
    vector<int> v(n);
    for(long long int i=0;i<n;i++)
     cin>>v[i];
      sort(v.begin(),v.end());
      long long int mx = 0,mn = 0;
      for(long long int i=0;i<n/2;i++)
      { 
         mx += (v[i+n/2] - v[i]);
         mn += (v[2*i+1] - v[2*i]);
      }
      cout<<mn<<" "<<mx<<endl;
      return 0;
}