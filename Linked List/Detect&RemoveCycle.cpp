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
void insertAtHead(node *&head, int val)
{
  node *n = new node(val);
  n->next = head;
  head = n;
}
void insertAtTail(node *&head, int val)
{
  node *n = new node(val);
  if (head == NULL)
  {
    head = n;
    return;
  }
  node *temp = head;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = n;
}
void display(node *head)
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
  delete temp;
}
void deletion(node *&head, int val)
{
  node *temp = head;
  if (head == NULL)
  {
    return;
  }
  if (head->next == NULL)
  {
    deletionAtHead(head);
    return;
  }
  while (temp->next->data != val)
  {
    temp = temp->next;
  }
  node *todelete = temp->next;
  temp->next = temp->next->next;
  delete todelete;
}
bool search(node *head, int key)
{
  node *temp = head;
  while (temp != NULL)
  {
    if (temp->data == key)
    {
      return true;
    }
    temp = temp->next;
  }
  return false;
}
void reverse(node *&head)
{
  node *prev = NULL;
  node *curr = head;
  node *nextptr;
  while (curr != NULL)
  {
    nextptr = curr->next;
    curr->next = prev;
    prev = curr;
    curr = nextptr;
  }
  node *temp = prev;
  while (temp != NULL)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}
node *reverseRecursive(node *&head)
{
  if (head == NULL || head->next == NULL)
  {
    return head;
  }
  node *newnode = reverseRecursive(head->next);
  head->next->next = head;
  head->next = NULL;

  return newnode;
}
node *reverseK(node *&head, int k)
{
  node *prevptr = NULL;
  node *currptr = head;
  node *nextptr;
  int count = 0;
  while (currptr != NULL && count < k)
  {
    nextptr = currptr->next;
    currptr->next = prevptr;
    prevptr = currptr;
    currptr = nextptr;
    count++;
  }
  if (nextptr != NULL)
  {
    head->next = reverseK(nextptr, k);
  }
  return prevptr;
}
void makeCycle(node *&head, int pos)
{
  node *temp = head;
  node *start;
  int count = 1;
  while (temp->next != NULL)
  {
    if (count == pos)
    {
      start = temp;
    }
    temp = temp->next;
    count++;
  }
  temp->next = start;
}
bool detectCycle(node *&head)
{
  node *slow = head;
  node *fast = head;
  while (fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
    if (fast == slow)
    {
      return true;
    }
  }
  return false;
}
void removeCycle(node *&head)
{
  node *slow = head;
  node *fast = head;
  do
  {
    slow = slow->next;
    fast = fast->next->next;
  } while (slow != fast);

  fast = head;
  while (slow->next != fast->next)
  {
    slow = slow->next;
    fast = fast->next;
  }
  slow->next = NULL;
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
  makeCycle(head, 3);
  // display(head);
  cout << detectCycle(head) << endl;
  removeCycle(head);
  cout << detectCycle(head) << endl;
  display(head);
  return 0;
}
