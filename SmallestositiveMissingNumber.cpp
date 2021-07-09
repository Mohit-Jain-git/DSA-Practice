#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  const int N = 1e6 + 2;
  bool idx[N];
  int ans = -1;
  for (int i = 0; i < n; i++)
  {
    idx[i] = 0;
  }
  for (int i = 0; i < n; i++)
  {
    if (a[i] >= 0)
    {
      idx[a[i]] = 1;
    }
  }
  for (int i = 0; i < N; i++)
  {
    if (idx[i] == 0)
    {
      ans = i;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}