/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
//-------------------------------------------------
// found the k-th to last element from an linked list
// i.e. Input : A->B->C->D->E, k = 3
//      Output: C
//-------------------------------------------------
// Execution result:
//
// Please input : ABCDE
// Index of element to pick: 3
// The linked list : A -> B -> C -> D -> E
// The kth to last element: C
//-------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

typedef char Data;

class Node
{
public:
  Data data;
  Node* next;
  Node(Data d, Node* p){data = d; next = p;}
}; // element of linked list

// construct new list
Node*
newList(string str) {
  Node* head = NULL;
  for(int i=str.size()-1; i>=0; i--)
  {
    Node* p = new Node(str[i], head);
    head = p;
  }
  return head;
}

inline ostream& operator<<(ostream& os, Node* head)
{
  for(Node *p = head; p!=NULL; p=p->next)
    os << p->data << (p->next ? " -> " : "");
  return os;
};

Node*
kthLast(Node* head, int k)
{
  if(head == NULL || k < 0) return NULL;

  Node *p = head, *q = NULL;

  // move the pointer p to k-th element
  for(size_t i=0; i<k; i++)
  {
    if(p != NULL) p = p->next;
    else return NULL;
  }

  q = head;
  //move p & q simultaneously
  while(p != NULL)
  {
    p = p->next;
    q = q->next;
  }
  // when p = last element, q is the k-th to last element
  return q; 
}

int
main()
{
  string input;
  int k;
  cout << " Please input : ";
  getline (cin, input); 
  cout << " Index of element to pick: ";
  cin >> k; 

  Node* head = newList(input);
  cout << " The linked list : " << head << endl;

  Node* p = kthLast(head, k);

  if(p != NULL)
    cout << " The kth to last element: " << p->data << endl;
  else
    cout << " Can not get the kth to last element!" << endl;

  return 0;
}
