#include <bits/stdc++.h>
using namespace std;

class Solution
{
  bool checkForCycle(int node, vector<int> adj[], int vis[], int dfsVis[])
  {
    vis[node] = 1;
    dfsVis[node] = 1;
    for (auto it : adj[node])
    {
      if (!vis[it])
      {
        if (checkForCycle(it, adj, vis, dfsVis))
          return true;
      }
      else if (dfsVis[it])
        return true;
    }
    dfsVis[node] = 0;
    return false;
  }

public:
  bool isCycle(int v, vector<int> adj[])
  {
    int vis[v], dfsVis[v];
    memset(vis, 0, sizeof(vis));
    memset(dfsVis, 0, sizeof(dfsVis));
    for (int i = 1; i <= v; i++)
    {
      if (!vis[i])
      {
        if (checkForCycle(i, adj, vis, dfsVis))
          return true;
      }
    }
    return false;
  }
};

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> adj[n + 1];
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }
  Solution obj;
  bool ans = obj.isCycle(n, adj);
  if (ans == 1)
    cout << "Cycle Detected.";
  else
    cout << "Cycle Not Detected.";
  cout << endl;
  return 0;
}