#include <bits/stdc++.h>
using namespace std;
int UpdateBit(int n, int pos, int value)
{
  int s = ~(1 << pos);
  n = n & s;
  return (n | (value < pos));
}
int main()
{
  int n;
  cin >> n;
  int pos;
  cin >> pos;
  int value;
  cin >> value;
  cout << UpdateBit(n, pos, value);
  return 0;
}