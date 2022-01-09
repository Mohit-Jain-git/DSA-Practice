#include <bits/stdc++.h>
using namespace std;

class Solution
{
  bool checkForCycle(int node, int parent, vector<int> adj[], vector<int> vis)
  {
    vis[node] = 1;
    for (auto it : adj[node])
    {
      if (!vis[it])
      {
        if (checkForCycle(it, node, adj, vis))
          return true;
      }
      else if (parent != it)
        return true;
    }
    return false;
  }

public:
  bool isCycle(int v, vector<int> adj[])
  {
    vector<int> vis(v + 1, 0);
    for (int i = 1; i <= v; i++)
    {
      if (!vis[i])
      {
        if (checkForCycle(i, -1, adj, vis))
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
    adj[v].push_back(u);
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