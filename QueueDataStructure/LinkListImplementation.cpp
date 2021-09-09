#include <bits/stdc++.h>
using namespace std;
class node
{
public:
  int data;
  node *next;
  node(int val)
  {
    data = val;
    next = NULL;
  }
};
class queu
{
public:
  node *front;
  node *back;

public:
  queu()
  {
    front = NULL;
    back = NULL;
  }
  void push(int x)
  {
    node *n = new node(x);
    if (front == NULL)
    {
      front = n;
      back = n;
      return;
    }
    back->next = n;
    back = n;
  }
  void pop()
  {
    if (front == NULL)
    {
      cout << "Queue Underflow" << endl;
      return;
    }
    node *todelete;
    todelete = front;
    front = front->next;
    delete todelete;
  }
  int peek()
  {
    if (front == NULL)
    {
      cout << "Queue Underflow" << endl;
      return -1;
    }
    return front->data;
  }
  bool empty()
  {
    if (front == NULL)
    {
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
  q.pop();
  cout << q.peek() << endl;
  cout << q.empty() << endl;
  q.pop();
  cout << q.peek() << endl;
  cout << q.empty() << endl;
  q.pop();
  cout << q.peek() << endl;
  cout << q.empty() << endl;
  q.pop();
  cout << q.peek() << endl;
  cout << q.empty() << endl;
  return 0;
}