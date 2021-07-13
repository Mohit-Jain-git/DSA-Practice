#include <bits/stdc++.h>
using namespace std;
int isPower2(int n)
{
  return (n && !(n & n - 1));
}
int main()
{
  int n;
  cin >> n;
  cout << isPower2(n) << endl;
  return 0;
}