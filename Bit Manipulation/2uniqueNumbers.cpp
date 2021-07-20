#include <bits/stdc++.h>
using namespace std;
int get2uniqueNumbers(int a[], int n)
{
  map<int, int> m;
  for (int i = 0; i < n; i++)
    m[a[i]]++;
  cout << "The non-repeating elements are: ";
  for (auto &x : m)
  {
    if (x.second == 1)
    {
      cout << x.first << " ";
    }
  }
}
int main()
{
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];
  get2uniqueNumbers(a, n);
  return 0;
}