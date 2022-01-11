#include <bits/stdc++.h>
using namespace std;
void findShortestPath(vector<int> adj[], int V, int src)
{
  int dist[V];
  for (int i = 0; i < V; i++)
  {
    dist[i] = INT_MAX;
  }
  queue<int> q;
  dist[src] = 0;
  q.push(src);
  while (!q.empty())
  {
    int node = q.front();
    q.pop();
    for (auto it : adj[node])
    {
      if (dist[node] + 1 < dist[it])
      {
        dist[it] = dist[node] + 1;
        q.push(it);
      }
    }
  }
  for (int i = 0; i < V; i++)
    cout << dist[i] << " ";
}
int main()
{
  int N, E;
  cin >> N >> E;

  vector<int> adj[N];

  for (int i = 0; i < E; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int src;
  cin >> src;
  findShortestPath(adj, N, src);
  return 0;
}