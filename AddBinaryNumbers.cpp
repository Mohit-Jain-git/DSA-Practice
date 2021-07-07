#include <bits/stdc++.h>
using namespace std;
int main()
{
  int a, b;
  cin >> a;
  cin >> b;
  int sum[20];
  int r = 0, i = 0;
  while (a != 0 || b != 0)
  {
    sum[i++] = ((a % 10 + b % 10 + r) % 2);
    r = ((a % 10 + b % 10 + r) / 2);
    a = a / 10;
    b = b / 10;
  }
  if (r != 0)
  {
    sum[i++] = r;
  }
  --i;
  while (i >= 0)
  {
    cout << sum[i--];
  }
  return 0;
}