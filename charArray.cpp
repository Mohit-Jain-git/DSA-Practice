#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin >> n;
  char a[n + 1];
  cin >> a;
  int flag = 0;
  for (int i = 0; i < n; i++)
  {
    if (a[i] != a[n - i - 1])
    {
      flag = 1;
      break;
    }
  }
  if (flag)
    cout << "Not Pailindrome";
  else
    cout << "Pailindrome";
  return 0;
}