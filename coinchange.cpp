#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{ 
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    { 
       cin>>v[i];
    }
    int x;
    cin>>x;
    sort(v.begin(),v.end(),greater<int>());
    int ans = 0;
    for(int i=0;i<n;i++)
    { 
        ans = ans + x/v[i];
        x = x - (x/v[i])*v[i];
    }
    cout<<ans<<endl;
    return 0;
}