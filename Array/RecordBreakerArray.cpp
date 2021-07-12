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
  int rb = 0;
  int ans = INT_MIN;
  int j = 0;
  if (n == 1)
  {
    cout << "1" << endl;
    return 0;
  }
  while (j < n)
  {
    if (j == n - 1)
    {
      if (a[j] > ans)
        rb++;
    }
    else
    {
      if (a[j] > ans && a[j] > a[j + 1])
      {
        rb++;
        ans = a[j];
      }
    }
    j++;
  }
  cout << rb << endl;
  return 0;
}