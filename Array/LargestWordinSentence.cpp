#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin >> n;
  cin.ignore();
  char a[n + 1];
  cin.getline(a, n);
  // cin.ignore();
  int curr = 0, mx = 0;
  for (int i = 0; i <= strlen(a); i++)
  {
    if (a[i] == ' ' || a[i] == '\0')
    {
      mx = max(curr, mx);
      curr = 0;
    }
    else
      curr++;
    if (a[i] == '\0')
      break;
  }
  cout << mx << endl;
  return 0;
}