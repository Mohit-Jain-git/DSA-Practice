#include <bits/stdc++.h>
using namespace std;
int LinearSearch(int a[], int n, int key)
{
  for (int i = 0; i < n; i++)
  {
    if (a[i] == key)
      return i;
  }
  return -1;
}
int main()
{
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int key;
  cin >> key;
  cout << LinearSearch(a, n, key);
  return 0;
}