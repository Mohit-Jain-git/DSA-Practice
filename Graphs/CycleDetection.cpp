#include <bits/stdc++.h>
using namespace std;

class Solution
{
  bool checkForCycle(int s, int v, vector<int> adj[], vector<int> vis)
  {
    queue<pair<int, int>> q;
    vis[s] = true;
    q.push({s, -1});
    while (!q.empty())
    {
      int node = q.front().first;
      int prev = q.front().second;
      q.pop();
      for (auto it : adj[node])
      {
        if (!vis[it])
        {
          vis[it] = true;
          q.push({it, node});
        }
        else if (prev != it)
          return true;
      }
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
        if (checkForCycle(i, v, adj, vis))
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