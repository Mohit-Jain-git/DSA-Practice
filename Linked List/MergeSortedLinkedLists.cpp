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

node *mergeRecursive(node *&head1, node *&head2)
{
  if (head1 == NULL)
  {
    return head2;
  }
  if (head2 == NULL)
  {
    return head1;
  }
  node *result;
  if (head1->data > head2->data)
  {
    result = head2;
    result->next = mergeRecursive(head1, head2->next);
  }
  else
  {
    result = head1;
    result->next = mergeRecursive(head1->next, head2);
  }
  return result;
}

node *merge(node *&head1, node *&head2)
{
  node *ptr1 = head1;
  node *ptr2 = head2;
  node *dummy = new node(-1);
  node *ptr3 = dummy;
  while (ptr1 != NULL && ptr2 != NULL)
  {
    if (ptr1->data > ptr2->data)
    {
      ptr3->next = ptr2;
      ptr2 = ptr2->next;
    }
    else
    {
      ptr3->next = ptr1;
      ptr1 = ptr1->next;
    }
    ptr3 = ptr3->next;
  }
  while (ptr1 != NULL)
  {
    ptr3->next = ptr1;
    ptr1 = ptr1->next;
    ptr3 = ptr3->next;
  }
  while (ptr2 != NULL)
  {
    ptr3->next = ptr2;
    ptr2 = ptr2->next;
    ptr3 = ptr3->next;
  }
  return dummy->next;
}
int main()
{
  node *head1 = NULL;
  node *head2 = NULL;
  insertAtTail(head1, 1);
  insertAtTail(head1, 3);
  insertAtTail(head1, 5);
  insertAtTail(head1, 9);
  insertAtTail(head1, 11);
  insertAtTail(head2, 2);
  insertAtTail(head2, 8);
  insertAtTail(head2, 6);
  display(head1);
  display(head2);
  // node *newhead = merge(head1, head2);
  // display(newhead);
  node *newhead = mergeRecursive(head1, head2);
  display(newhead);
  return 0;
}