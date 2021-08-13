#include <bits/stdc++.h>
using namespace std;
class node
{
public:
  int data;
  node *next;
  node *prev;
  node(int val)
  {
    data = val;
    next = NULL;
    prev = NULL;
  }
};
void insertAtHead(node *&head, int val)
{
  node *n = new node(val);
  n->next = head;
  if (head != NULL)
  {
    head->prev = n;
  }
  head = n;
}
void insertAtTail(node *&head, int val)
{
  if (head == NULL)
  {
    insertAtHead(head, val);
    return;
  }
  node *n = new node(val);
  node *temp = head;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = n;
  n->prev = temp;
}
void display(node *&head)
{
  node *temp = head;
  while (temp != NULL)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}
void deletionAtHead(node *&head)
{
  node *temp = head;
  head = head->next;
  head->prev = NULL;
  delete temp;
}
void deletion(node *&head, int pos)
{
  if (pos == 1)
  {
    deletionAtHead(head);
    return;
  }
  node *temp = head;
  int count = 1;
  while (temp != NULL && count != pos)
  {
    temp = temp->next;
    count++;
  }
  temp->prev->next = temp->next;
  if (temp->next != NULL)
  {
    temp->next->prev = temp->prev;
  }
  delete temp;
}
int length(node *&head)
{
  node *temp = head;
  int l = 0;
  while (temp != NULL)
  {
    temp = temp->next;
    l++;
  }
  return l;
}
node *appendK(node *&head, int k)
{
  node *newhead;
  node *newtail;
  node *temp = head;
  int l = length(head);
  k = k % l;
  int count = 1;
  while (temp->next != NULL)
  {
    if (count == l - k)
    {
      newtail = temp;
    }
    if (count == l - k + 1)
    {
      newhead = temp;
    }
    temp = temp->next;
    count++;
  }
  newtail->next = NULL;
  temp->next = head;
  return newhead;
}
int main()
{
  node *head = NULL;
  insertAtTail(head, 1);
  insertAtTail(head, 2);
  insertAtTail(head, 3);
  insertAtTail(head, 4);
  insertAtTail(head, 5);
  insertAtTail(head, 6);
  display(head);
  // insertAtHead(head, 6);
  // display(head);
  // deletion(head, 1);
  // display(head);
  node *newhead = appendK(head, 3);
  display(newhead);
  return 0;
}