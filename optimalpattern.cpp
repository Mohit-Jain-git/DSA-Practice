#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second
int main()
{ 
   int n;
   cin>>n;
   vi v(n);
   rep(i,0,n)
   { 
      cin>>v[i];
   }
   priority_queue<int,vi,greater<int>> minheap;
   rep(i,0,n)
   { 
      minheap.push(v[i]);
   }
    int sum = 0;
    while(minheap.size()>1)
    { 
        int e1 = minheap.top();
        minheap.pop();
        int e2 = minheap.top();
        minheap.pop();
        sum += e1 + e2;
        minheap.push(e1 + e2);
    }
    cout<<sum<<endl;
    return 0;
}