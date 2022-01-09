#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> adj[n + 1];
  vector<pair<int, int>> adj[n + 1]; // if there is a weighted graph.
  for (int i = 0; i < m; i++)
  {
    int u, v, wt;
    cin >> u >> v >> wt;
    adj[u].push_back(v);
    adj[v].push_back(u);
    // adj[u].push_back({v, wt});   if there is a weighted graph.
    // adj[v].push_back({u, wt});
  }
  return 0;
}