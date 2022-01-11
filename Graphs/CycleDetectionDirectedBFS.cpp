#include <bits/stdc++.h>
using namespace std;
bool isCyclic(int V, vector<int> adj[])
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
  int count = 0;
  while (!q.empty())
  {
    int node = q.front();
    q.pop();
    count++;
    for (auto it : adj[node])
    {
      indegree[it]--;
      if (indegree[it] == 0)
        q.push(it);
    }
  }
  if (count == V)
    return false;
  return true;
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
  }
  if (isCyclic(N, adj) == true)
    cout << "Yes";
  else
    cout << "No";
  return 0;
}