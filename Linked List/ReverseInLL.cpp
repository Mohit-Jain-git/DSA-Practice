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
int main()
{
  node *head = NULL;
  insertAtTail(head, 1);
  insertAtTail(head, 2);
  insertAtTail(head, 3);
  display(head);
  // insertAtHead(head, 4);
  // display(head);
  // cout << search(head, 4) << endl;
  // deletionAtHead(head);
  // display(head);
  // node *newhead = reverse(head);
  // display(newhead);
  // reverseRecursive
  node *newhead = reverseRecursive(head);
  // reverse(head);
  display(newhead);
  return 0;
}
