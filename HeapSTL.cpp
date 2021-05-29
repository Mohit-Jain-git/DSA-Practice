#include<bits/stdc++.h>
using namespace std;
int main()
{ 
  priority_queue<int,vector<int>>pq;
  pq.push(2);
  pq.push(3);
  pq.push(1);
  cout<<pq.top();
  cout<<endl;
  pq.pop();
  cout<<pq.top();
  cout<<endl;
  priority_queue<int,vector<int>,greater<int>>pqm;
  pqm.push(2);
  pqm.push(1);
  pqm.push(3);
  cout<<pqm.top();
  cout<<endl;
  pqm.pop();
  cout<<pqm.top();
  cout<<endl;
   return 0;
}