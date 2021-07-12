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
vi adj[N];
bool vis[N];
void dfs(int node)
{ 
    vis[node]=1;
    // cout<<node<<" "; preorder
    vi :: iterator it;
    for(it=adj[node].begin();it!=adj[node].end();it++)
    { 
        if(!vis[*it])
         dfs(*it);
    }
     cout<<node<<" "; // postorder
}
signed main()
{ 
    int n,m;
    rep(i,0,N)
     vis[i] = 0;
     cin>>n>>m;
     rep(i,0,m)
     { 
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
     }
     dfs(1);
     return 0;
}