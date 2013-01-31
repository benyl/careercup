/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
//-------------------------------------------------
// add two numbers represended by a linked list, 
// where each nodes contains one digits
// version 1: number store in reverse order
// version 2: number store in forward order
// i.e. ver.1: input : 617 (7->1->6) + 295 (5->9->2)
//             output: 912 (2->1->9)
// i.e. ver.1: input : 617 (6->1->7) + 295 (2->9->5)
//             output: 912 (9->1->2)
//-------------------------------------------------
// Execution result:
//
// Please input string 1: 617
// Please input string 2: 295
// The linked list of 617 : 6 -> 1 -> 7
// The linked list of 295 : 2 -> 9 -> 5
// The sum of them is 912 : 9 -> 1 -> 2
//-------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

typedef int Data;

class Node
{
public:
  Data data;
  Node* pre;
  Node* next;
  Node(Data d, Node *p, Node *n){data = d; pre = p; next = n;}
}; // element of doubly linked list

inline ostream& operator<<(ostream& os, Node* head)
{
  for(Node *p = head; p!=NULL; p=p->next)
    os << p->data << (p->next ? " -> " : "");
  return os;
};

// construct new list in reverse order
Node*
newRevList(string str) {
  Node* head = NULL;
  for(int i=0; i<str.size(); i++)
  {
    Node* p = new Node(str[i] - 48, NULL, head);
    if(head != NULL) head->pre = p;
    head = p;
  }
  return head;
}

// construct new list in forward order
Node*
newFwdList(string str) {
  Node* head = NULL;
  for(int i=str.size()-1; i>=0; i--)
  {
    Node* p = new Node(str[i] - 48, NULL, head);
    if(head != NULL) head->pre = p;
    head = p;
  }
  return head;
}

// add linked list in reverse order
int
addRev (Node *& h1, Node* h2)
{
  if(h1 == NULL || h2 == NULL)
  {
    if(h1 == NULL) h1 = h2;

    // get the sum from linked list in reverse order
    int sum = 0, temp = 1;
    for(Node* p = h1; p!=NULL; p = p->next)
    {
      sum += p->data * temp;
      temp *= 10;
    }

    return sum;
  }

  Node* head = h1;

  // add h2 to h1
  bool carry = false; // the carry bit
  while(h2!=NULL)
  {
    h1->data += h2->data + carry;
    carry = h1->data > 9 ? true : false;
    h1->data %= 10;

    if(h1->next == NULL)
    { // if h1 reach the end
      if(h2->next !=NULL)
      { // move the rest of h2 to h1
        h1->next = h2->next;
        h1->next->pre = h1;
        h2->next = NULL;

        h1 = h1->next;
      }
      else if(carry)
      { // add new node for carry
        Node* p = new Node(0, h1, NULL);
        h1->next = p;

        h1 = h1->next;
      }
      break;
    } // END : if(h1->next == NULL)

    h1 = h1->next;
    h2 = h2->next;
  } // END : while(h2!=NULL)

  while(carry)
  {
    h1->data += carry;
    carry = h1->data > 9 ? true : false;
    h1->data %= 10;

    if(h1->next == NULL && carry)
    { // add new node for carry
      Node* p = new Node(0, h1, NULL);
      h1->next = p;
    }

    h1 = h1->next;
  }
  
  h1 = head;

  // get the sum from linked list in reverse order
  int sum = 0, temp = 1;
  for(Node* p = h1; p!=NULL; p = p->next)
  {
    sum += p->data * temp;
    temp *= 10;
  }

  return sum;
}

// add linked list in forward order
int
addFwd (Node *& h1, Node* h2)
{
  if(h1 == NULL || h2 == NULL)
  {
    if(h1 == NULL) h1 = h2;

    // get the sum from linked list in forward order
    int sum = 0;
    for(Node* p = h1; p!=NULL; p = p->next)
    {
      sum *= 10;
      sum += p->data;
    }

    return sum;
  }

  // move h1 and h2 to the end of list
  while(h1->next != NULL) h1 = h1->next;
  while(h2->next != NULL) h2 = h2->next;

  // add h2 to h1
  bool carry = false; // the carry bit
  while(h2!=NULL)
  {
    h1->data += h2->data + carry;
    carry = h1->data > 9 ? true : false;
    h1->data %= 10;

    if(h1->pre == NULL)
    { // if h1 reach the end
      if(h2->pre !=NULL)
      { // move the rest of h2 to h1
        h1->pre = h2->pre;
        h1->pre->next = h1;
        h2->pre = NULL;

        h1 = h1->pre;
      }
      else if(carry)
      { // add new node for carry
        Node* p = new Node(0, NULL, h1);
        h1->pre = p;

        h1 = h1->pre;
      }
      break;
    } // END : if(h1->next == NULL)

    h1 = h1->pre;
    h2 = h2->pre;
  } // END : while(h2!=NULL)

  while(carry)
  {
    h1->data += carry;
    carry = h1->data > 9 ? true : false;
    h1->data %= 10;

    if(h1->pre == NULL && carry)
    { // add new node for carry
      Node* p = new Node(0, NULL, h1);
      h1->pre = p;
    }

    if(h1->pre != NULL) h1 = h1->pre;
  }
  
  // move to the head of the list
  while(h1->pre != NULL) h1 = h1->pre;

  // get the sum from linked list in reverse order
  int sum = 0;
  for(Node* p = h1; p!=NULL; p = p->next)
  {
    sum *= 10;
    sum += p->data;
  }

  return sum;
}


int
main()
{
  string s1, s2;
  cout << " Please input string 1: ";
  getline (cin, s1);
  cout << " Please input string 2: ";
  getline (cin, s2);
/*
  // construct new array
  Node *h1 = newRevList(s1);
  Node *h2 = newRevList(s2);
  cout << " The linked list of " << s1 << " : " << h1 << endl;
  cout << " The linked list of " << s2 << " : " << h2 << endl;

  int sum = addRev(h1, h2);

  cout << " The sum of them is " << sum << " : " << h1 << endl;
*/
  // construct new array
  Node *h1 = newFwdList(s1);
  Node *h2 = newFwdList(s2);
  cout << " The linked list of " << s1 << " : " << h1 << endl;
  cout << " The linked list of " << s2 << " : " << h2 << endl;

  int sum = addFwd(h1, h2);

  cout << " The sum of them is " << sum << " : " << h1 << endl;
  return 0;
}
