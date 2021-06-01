#include<bits/stdc++.h>
#define ll long long int
#define vi vector<ll>
#define pii pair<ll,ll>
#define vii vector<pii>
#define rep(i,a,b) for(ll i=a;i<b;i++)
using namespace std;
int main()
{ 
   ll k;
   cin>>k;
   vector<vector<ll>> a(k);
   rep(i,0,k)
   { 
       ll size;
       cin>>size;
       a[i] = vi(size);
       rep(j,0,size)
       {
          cin>>a[i][j];
       }
   } 
     vi idx(k,0);
     priority_queue<pii,vii,greater<pii>> pq;
     rep(i,0,k)
     { 
         pii p;
         p.first = a[i][0];
         p.second = i;
        pq.push(p);        
     }
     vi ans;
     
     while(!pq.empty())
     { 
         pii x = pq.top();
         pq.pop();
           ans.push_back(x.first);
         if(idx[x.second]+1 < a[x.second].size())
         {
           pii p;
           p.first = a[x.second][idx[x.second]+1];
           p.second = x.second;
           pq.push(p);
         }

          idx[x.second] += 1;

     }
      rep(i,0,ans.size())
      { 
         cout<<ans[i]<<endl;
      }
      cout<<endl;
     return 0;
}
