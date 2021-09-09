#include <bits/stdc++.h>
using namespace std;
#define n 20
class queu
{
private:
  int *arr;
  int front;
  int back;

public:
  queu()
  {
    arr = new int[n];
    front = -1;
    back = -1;
  }
  void push(int x)
  {
    if (back == n - 1)
    {
      cout << "Queue Overflow\n";
      return;
    }
    back++;
    arr[back] = x;
    if (front == -1)
    {
      front++;
    }
  }
  void pop()
  {
    if (front == -1 || front > back)
    {
      cout << "Queue is Empty" << endl;
      return;
    }
    else
      front++;
  }
  int peek()
  {
    if (front == -1 || front > back)
    {
      cout << "Queue is Empty" << endl;
      return -1;
    }
    return arr[front];
  }
  bool empty()
  {
    if (front == -1 || front > back)
    {
      cout << "Queue is Empty" << endl;
      return true;
    }
    return false;
  }
};

int main()
{
  queu q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  q.push(5);
  q.pop();
  q.pop();
  cout << q.peek() << endl;
  cout << q.empty() << endl;
  return 0;
}
