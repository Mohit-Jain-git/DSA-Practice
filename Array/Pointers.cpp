#include <bits/stdc++.h>
using namespace std;
int main()
{
  // int a = 10;
  // int *ptr = &a;
  // cout << ptr;

  // Array of Pointers;
  int a[] = {10, 20, 30};
  // cout << *a << endl;
  int *ptr = a;
  for (int i = 0; i < 3; i++)
  {
    // cout << *ptr << endl;
    // ptr++;
    cout << *(a + i) << endl;
  }
  return 0;
}