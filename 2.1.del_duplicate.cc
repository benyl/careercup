/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
//-------------------------------------------------
// remove duplicates from an unsorted linked list
// i.e. input : A->B->C->C->D
//      output: A->B->C->D
//-------------------------------------------------
// Execution result:
//
// Please input : ABCCD
// The linked list : A -> B -> C -> C -> D
// Duplicate found : C
// Delete duplicate: A -> B -> C -> D
//-------------------------------------------------
#include <iostream>
#include <string>
#include <set>
using namespace std;

typedef char Data;

class Node
{
public:
  Data data;
  Node* next;
  Node(Data d, Node* p){data = d; next = p;}
}; // element of linked list

// construct new linked list
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
delDup(Node* head)
{
  if(head == NULL) return;

  set <Data> appear;
  Node *p = head, *pre = NULL;
  while(p!=NULL)
  {
    // if appear before, remove the node
    if(appear.count(p->data))
    {
      cout << " Duplicate found : " << p->data << endl;
      pre->next = p->next;
      delete p;
      p = pre->next;
    }
    else // if the node not appear before
    {
      appear.insert(p->data);
      pre = p;
      p = p->next;
    }
  }
}

void
delDupV2(Node* head)
{
  if(head == NULL) return;

  Node *p = head, *pre = NULL, *s = NULL;
  while(p!=NULL)
  {
    // search the previous nodes to check duplicate
    for(s=head; s!=p; s=s->next)
    {
      if(s->data == p->data) 
        break;
    }
    // if appear before, that s is not equal to p, remove p
    if(s!=p)
    {
      cout << " Duplicate found : " << p->data << endl;
      pre->next = p->next;
      delete p;
      p = pre->next;
    }
    else // if the node not appear before
    {
      pre = p;
      p = p->next;
    }
  }
}


int
main()
{
  string input;
  cout << " Please input : ";
  getline (cin, input); 

  Node* head = newList(input);
  cout << " The linked list : " << head << endl;

  delDupV2(head);

  cout << " Delete duplicate: " << head << endl;

  return 0;
}
