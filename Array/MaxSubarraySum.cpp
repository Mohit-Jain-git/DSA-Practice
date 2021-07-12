#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n, sum = 0, mx = INT_MIN;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  // for (int i = 0; i < n; i++)
  // {
  //   sum = 0;
  //   for (int j = i; j < n; j++)
  //   {
  //     sum += a[j];
  //   }
  //   mx = max(mx, sum);
  // }
  for (int i = 0; i < n; i++)
  {
    sum = sum + a[i];
    if (sum < 0)
      sum = 0;
    mx = max(mx, sum);
  }
  cout << mx << endl;
  return 0;
}