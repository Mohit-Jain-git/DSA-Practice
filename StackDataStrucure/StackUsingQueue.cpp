#include <bits/stdc++.h>
using namespace std;
class stak
{
  queue<int> q1, q2;
  int size;

public:
  stak()
  {
    size = 0;
  }
  void push(int x)
  {
    size++;
    q2.push(x);
    while (!q1.empty())
    {
      q2.push(q1.front());
      q1.pop();
    }
    queue<int> q = q1;
    q1 = q2;
    q2 = q;
  }
  void pop()
  {
    if (q1.empty())
      return;
    q1.pop();
    size--;
  }
  int top()
  {
    if (q1.empty())
      return -1;
    return q1.front();
  }
  int siz()
  {
    return size;
  }
};
int main()
{
  stak s;
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  s.push(5);
  cout << s.top() << endl;
  s.pop();
  cout << s.top() << endl;
  s.pop();
  cout << s.top() << endl;
  s.pop();
  cout << s.siz() << endl;
  return 0;
}