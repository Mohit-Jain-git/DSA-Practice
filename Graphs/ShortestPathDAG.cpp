#include <bits/stdc++.h>
using namespace std;
void findTopoSort(int node, stack<int> &st, int vis[], vector<pair<int, int>> adj[])
{
  vis[node] = 1;
  for (auto it : adj[node])
  {
    if (!vis[it.first])
    {
      findTopoSort(it.first, st, vis, adj);
    }
  }
  st.push(node);
}
void shortestPath(int src, int N, vector<pair<int, int>> adj[])
{
  int vis[N];
  memset(vis, 0, sizeof(vis));
  stack<int> st;
  for (int i = 0; i < N; i++)
  {
    if (!vis[i])
    {
      findTopoSort(i, st, vis, adj);
    }
  }
  int dist[N];
  for (int i = 0; i < N; i++)
  {
    dist[i] = INT_MAX;
  }
  dist[src] = 0;
  while (!st.empty())
  {
    int node = st.top();
    st.pop();
    if (dist[node] != INT_MAX)
    {
      for (auto it : adj[node])
      {
        if (dist[node] + it.second < dist[it.first])
          dist[it.first] = dist[node] + it.second;
      }
    }
  }
  for (int i = 0; i < N; i++)
  {
    if (dist[i] == INT_MAX)
      cout << "INF";
    else
      cout << dist[i] << " ";
  }
}
int main()
{
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> adj[n];
  for (int i = 0; i < m; i++)
  {
    int u, v, wt;
    cin >> u >> v >> wt;
    adj[u].push_back({v, wt});
  }
  shortestPath(0, n, adj);
  return 0;
}