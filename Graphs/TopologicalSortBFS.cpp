#include <bits/stdc++.h>
using namespace std;
vector<int> topoSort(int V, vector<int> adj[])
{
  int indegree[V];
  queue<int> q;
  memset(indegree, 0, sizeof(indegree));
  for (int i = 0; i < V; i++)
  {
    for (auto it : adj[i])
    {
      indegree[it]++;
    }
  }
  for (int i = 0; i < V; i++)
  {
    if (indegree[i] == 0)
      q.push(i);
  }
  vector<int> topo;
  while (!q.empty())
  {
    int node = q.front();
    q.pop();
    topo.push_back(node);
    for (auto it : adj[node])
    {
      indegree[it]--;
      if (indegree[it] == 0)
        q.push(it);
    }
  }
  return topo;
}

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    int N, E;
    cin >> N >> E;

    vector<int> adj[N];

    for (int i = 0; i < E; i++)
    {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
    }
    vector<int> res = topoSort(N, adj);
    for (int i = 0; i < res.size(); i++)
    {
      cout << res[i] << " ";
    }
  }

  return 0;
}