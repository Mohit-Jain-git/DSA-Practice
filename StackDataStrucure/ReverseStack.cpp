#include <bits/stdc++.h>
using namespace std;
void insertAtBottom(stack<int> &st, int el)
{
  if (st.empty())
  {
    st.push(el);
    return;
  }
  int topl = st.top();
  st.pop();
  insertAtBottom(st, el);
  st.push(topl);
}
void reversestack(stack<int> &st)
{
  if (st.empty())
  {
    return;
  }
  int el = st.top();
  st.pop();
  reversestack(st);
  insertAtBottom(st, el);
}
int main()
{
  stack<int> st;
  st.push(1);
  st.push(2);
  st.push(3);
  st.push(4);
  reversestack(st);
  while (!st.empty())
  {
    cout << st.top() << " ";
    st.pop();
  }
  cout << endl;
  return 0;
}