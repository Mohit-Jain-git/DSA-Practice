#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> bfsOfGraph(int v, vector<int> adj[])
  {
    vector<int> bfs;
    vector<int> vis(v + 1, 0);
    for (int i = 1; i <= v + 1; i++)
    {
      if (!vis[i])
      {
        queue<int> q;
        q.push(i);
        vis[i] = 1;
        while (!q.empty())
        {
          int node = q.front();
          q.pop();
          bfs.push_back(node);

          for (auto it : adj[node])
          {
            if (!vis[it])
            {
              q.push(it);
              vis[it] = 1;
            }
          }
        }
      }
    }
    return bfs;
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
    // adj[v].push_back(u);
  }
  Solution obj;
  vector<int> ans = obj.bfsOfGraph(n, adj);
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}