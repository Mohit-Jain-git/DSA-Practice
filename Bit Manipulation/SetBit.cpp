#include <bits/stdc++.h>
using namespace std;
int SetBit(int n, int pos)
{
  return (n | (1 << pos));
}
int main()
{
  int n;
  cin >> n;
  int pos;
  cin >> pos;
  cout << SetBit(n, pos) << endl;
  return 0;
}
