#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second 
const int N = 1e5 + 2;
const int MOD = 1e9 + 7;
signed main()
{ 
    int n,m;
    vi adjl[N];
    cin>>n>>m;
    rep(i,0,m)
    { 
       int x,y;
       cin>>x>>y;
       adjl[x].push_back(y);
       adjl[y].push_back(x);
    }
    cout<<"Adjacency list of the above graph is given by:"<<endl;
    rep(i,1,n+1)
    { 
       cout<<i;
       vi :: iterator it;
       for(it=adjl[i].begin();it!=adjl[i].end();it++)
        cout<<"->"<<*it;
        cout<<endl;
    }
     return 0;
}