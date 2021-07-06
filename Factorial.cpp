#include<bits/stdc++.h>
using namespace std;
void fact(int n)
{
  int factorial = 1;
  for (int i = 2; i <= n;i++)
  {
    factorial *= i;
  }
  cout << factorial << endl;
}
int main()
{
    int n;
    cin>>n;
    fact(n);
    return 0;
}