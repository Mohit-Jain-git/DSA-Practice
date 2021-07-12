#include <bits/stdc++.h>
using namespace std;
int kadanes(int a[], int n)
{
  int sum = 0;
  int mx = INT_MIN;
  for (int i = 0; i < n; i++)
  {
    sum += a[i];
    if (sum < 0)
      sum = 0;
    mx = max(mx, sum);
  }
  return mx;
}
int main()
{
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  int wrapsum, nonwrapsum;
  nonwrapsum = kadanes(a, n);
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += a[i];
    a[i] = -a[i];
  }

  wrapsum = sum + kadanes(a, n);
  cout << max(wrapsum,nonwrapsum) << endl;
  return 0;
}