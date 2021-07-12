#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n, m, x;
  cin >> n >> m >> x;
  int a[n][m];
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> a[i][j];
    }
  }
  int r = 0, c = m - 1;
  int flag = 0;
  while (r < n && c >= 0)
  {
    if (a[r][c] == x)
    {
      flag = 1;
      break;
    }
    if (a[r][c] > x)
    {
      c--;
    }
    else
    {
      r++;
    }
  }
  if (flag)
    cout << "Element Found" << endl;
  else
    cout << "Element not Found" << endl;
  return 0;
}