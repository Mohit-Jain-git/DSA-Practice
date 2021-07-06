#include<bits/stdc++.h>
using namespace std;
int binaryToDecimal(int n)
{
  int ans = 0;
  int x = 1;
  while(n>0)
  {
    int y = n % 10;
    ans = ans + x * y;
    x = x * 2;
    n = n / 10;
  }
  return ans;
}
int octalToDecimal(int n)
{ 
  int ans = 0;
  int x = 1;
  while(n>0)
  {
    int y = n % 10;
    ans = ans + x * y;
    x = x * 8;
    n = n / 10;
  }
  return ans;
}
int hexadecimalToDecimal(string n)
{
  int s = n.size();
  int ans = 0;
  int x = 1;
  for (int i = s - 1; i >= 0;i--)
  { 
     if(n[i]>='0' && n[i]<='9')
     {
       ans = ans + x * (n[i] - '0');
     }
     else if(n[i]>='A' && n[i]<='F')
     {
       ans = ans + x * (n[i] - 'A' + 10);
     }
     x = x * 16;
  }
  return ans;
}
void decimalToBinary(int n)
{
  int i = 0;
  int a[32];
  while(n>0)
  {
    a[i] = n % 2;
    i++;
    n = n / 2;
  }
  for(int j = i - 1; j >= 0;j--)
   {
     cout << a[j];
   }
}
void decimalToOctal(int n)
{ 
  int i = 0;
  int a[32];
  while(n>0)
  {
    a[i] = n % 8;
    i++;
    n = n / 8;
  }
  for(int j = i - 1; j >= 0;j--)
   {
     cout << a[j];
   }
}
void decimalToHexadecimal(int n)
{ 
  int i = 0;
  char a[32];
  while(n>0)
  {
    int temp  = n % 16;
    if(temp<10)
    {
      a[i] = temp + 48;
      i++;
    }
    else
    {
      a[i] = temp + 55;
      i++;
    }
    n = n / 16;
  }
  for(int j = i - 1; j >= 0;j--)
   {
     cout << a[j];
   }
}
int main()
{
  int n;
  // string n;
  cin >> n;
  // cout << binaryToDecimal(n)<<endl;
  // cout << octalToDecimal(n) << endl;
  // cout << hexadecimalToDecimal(n) << endl;
  //  decimalToBinary(n);
  // decimalToOctal(n);
  decimalToHexadecimal(n);
  return 0;
}