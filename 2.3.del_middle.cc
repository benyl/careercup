/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
//-------------------------------------------------
// delete a middle node from a linked list gived only access to that node.
// i.e. Input : A->B->C->D->E  *C
//      Output: A->B->D->E
//-------------------------------------------------
// Execution result:
//
// Please input : ABCDE
// Input the number of node to delete: 3
// The linked list : A -> B -> C -> D -> E
// Delete k-th node: A -> B -> D -> E
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

void
delMid (Node* p)
{
  // If *p is the last node
  if(p->next == NULL) {
    cout << " This is not a middle element!" << endl;
    return;
  }

  // copy the next node to this node, and delete the next node
  Node *q = p->next;
  p->data = q->data;
  p->next = q->next;

  delete q;
}


int
main()
{
  string input;
  int k;
  cout << " Please input : ";
  getline (cin, input); 
  cout << " Input the number of node to delete: ";
  cin >> k; 

  Node* head = newList(input);
  cout << " The linked list : " << head << endl;

  // move the pointer p to k-th element
  Node *q = head;
  for(size_t i=1; i<k; i++)
  {
    if(q->next != NULL) q = q->next;
    else 
    {
      cout << " the linked list is shorter than k!" << endl;
      return 0;
    }
  }

  delMid(q);

  cout << " Delete k-th node: " << head << endl;

  return 0;
}
