#include <bits/stdc++.h>
using namespace std;
class student
{
public:
  void fun()
  {
    cout << "I am a function with no argument." << endl;
  }
  void fun(int x)
  {
    cout << "I am a function with int argument." << endl;
  }
  void fun(double x)
  {
    cout << "I am a function with double argument." << endl;
  }
};
int main()
{
  student s;
  s.fun();
  s.fun(2);
  s.fun(2.4);
  return 0;
}