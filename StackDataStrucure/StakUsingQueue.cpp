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
  void pop()
  {
    if (q1.empty())
    {
      return;
    }
    while (q1.size() != 1)
    {
      q2.push(q1.front());
      q1.pop();
    }
    q1.pop();
    size--;
    queue<int> temp = q1;
    q1 = q2;
    q2 = temp;
  }
  void push(int x)
  {
    q1.push(x);
    size++;
  }
  int top()
  {
    if (q1.empty())
    {
      return -1;
    }
    while (q1.size() != 1)
    {
      q2.push(q1.front());
      q1.pop();
    }
    int ans = q1.front();
    q2.push(ans);
    queue<int> temp = q1;
    q1 = q2;
    q2 = temp;
    return ans;
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
  cout << s.top() << endl;
  s.pop();
  cout << s.top() << endl;
  cout << s.siz() << endl;
  return 0;
}