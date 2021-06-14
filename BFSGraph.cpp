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
    vi adj[N];
    bool vis[N];
    rep(i,0,N)
     vis[i]=0;
    int n,m;
    cin>>n>>m;
    rep(i,0,m)
    { 
       int x,y;
       cin>>x>>y;
       adj[x].push_back(y);
       adj[y].push_back(x);
    }
    queue<int> q;
    q.push(1);
    vis[1] = true;
    while(!q.empty())
    { 
       int node = q.front();
       q.pop();
       cout<<node<<endl;
       vi :: iterator it;
       for(it = adj[node].begin();it!=adj[node].end();it++)
       { 
           if(!vis[*it])
           { 
               vis[*it]=1;
               q.push(*it);
           }
       }
    }
   return 0;
}