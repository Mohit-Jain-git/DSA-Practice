#include <bits/stdc++.h>
using namespace std;
int ClearBit(int n, int pos)
{
  int s = ~(1 << pos);
  return (n & s);
}
int main()
{
  int n;
  cin >> n;
  int pos;
  cin >> pos;
  cout << ClearBit(n, pos);
  return 0;
}