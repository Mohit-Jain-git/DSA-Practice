#include <bits/stdc++.h>
using namespace std;
int numberOf1(int n)
{
  int count = 0;
  while (n)
  {
    n = n & (n - 1);
    count++;
  }
  return count;
}
int main()
{
  int n;
  cin >> n;
  cout << numberOf1(n) << endl;
  return 0;
}