#include<bits/stdc++.h>
using namespace std;
int main()
{ 
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    map<int,int> count;
    int presum=0;
    for(int i=0;i<n;i++)
    { 
        presum += a[i];
        count[presum]++;
    }
    int ans=0;
    map<int,int> :: iterator it;
    for(it = count.begin();it!=count.end();it++)
    { 
        int s = it->second;
        ans += (s*(s-1))/2;
        if(it->first==0)
        ans += it->second;
    }
    cout<<ans<<endl;
    return 0;
}