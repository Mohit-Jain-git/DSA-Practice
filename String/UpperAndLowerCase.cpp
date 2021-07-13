#include <bits/stdc++.h>
using namespace std;
int main()
{
  // convert to upper case

  // string s = "mohit";
  // for (int i = 0; i < s.size(); i++)
  // {
  //   if (s[i] >= 'a' && s[i] <= 'z')
  //     s[i] = s[i] - 32;
  // }
  // cout << s;

  // convert to lower case

  string s = "MOHIT";
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] >= 'A' && s[i] <= 'Z')
      s[i] = s[i] + 32;
  }
  cout << s;
  return 0;
}