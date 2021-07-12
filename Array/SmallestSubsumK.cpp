#include<bits/stdc++.h>
#define ll long long int
#define vi vector<ll>
#define pii pair<ll,ll>
#define vii vector<pii>
#define rep(i,a,b) for(ll i=a;i<b;i++)
using namespace std;
int main()
{ 
    ll n,k;
    cin>>n>>k;
    vi a(n);
    rep(i,0,n)
    {
       cin>>a[i];
    }
    priority_queue<ll,vi> pq;
    rep(i,0,n)
    {
       pq.push(a[i]);
    }
    ll sum=0;
    ll c=0;
    while(!pq.empty())
    { 
        sum += pq.top();
        pq.pop();
        c++;
        if(sum>=k)
        break;
    }
    if(sum<k)
    cout<<"-1"<<endl;
    else
    cout<<c<<endl;
    return 0;
}