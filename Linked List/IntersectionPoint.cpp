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
void intersect(node *&head1, node *&head2, int pos)
{
  node *temp1 = head1;
  while (pos--)
  {
    temp1 = temp1->next;
  }
  node *temp2 = head2;
  while (temp2->next != NULL)
  {
    temp2 = temp2->next;
  }
  temp2->next = temp1;
}
int intersection(node *&head1, node *&head2)
{
  int l1 = length(head1);
  int l2 = length(head2);
  int d;
  node *ptr1, *ptr2;
  if (l1 > l2)
  {
    d = l1 - l2;
    ptr1 = head1;
    ptr2 = head2;
  }
  else
  {
    d = l2 - l1;
    ptr1 = head2;
    ptr2 = head1;
  }
  while (d)
  {
    ptr1 = ptr1->next;
    if (ptr1 == NULL)
    {
      return -1;
    }
    d--;
  }

  while (ptr1 != NULL && ptr2 != NULL)
  {
    if (ptr1 == ptr2)
    {
      return ptr1->data;
    }
    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
  }
  return -1;
}
int main()
{
  node *head1 = NULL;
  node *head2 = NULL;
  insertAtTail(head1, 1);
  insertAtTail(head1, 2);
  insertAtTail(head1, 3);
  insertAtTail(head1, 4);
  insertAtTail(head1, 5);
  insertAtTail(head1, 6);
  insertAtTail(head2, 9);
  insertAtTail(head2, 10);
  intersect(head1, head2, 3);
  display(head1);
  display(head2);
  cout << intersection(head1, head2);
  return 0;
}