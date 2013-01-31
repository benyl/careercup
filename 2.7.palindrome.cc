/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
//-------------------------------------------------
// check if a linked list is a palindrome
// i.e. Input : A->B->C->B->A
//      Output: This linked list is a palindrome.
//-------------------------------------------------
// Execution result:
//
// Please input : ABCBA
// The linked list : A -> B -> C -> B -> A
// This linked list is palindrome.
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

Node *
palindrome (Node* head, int len)
{
  if(head == NULL) return false;

  if(len == 0) return head;
  if(len == 1) return head->next;

  Node* end = palindrome (head->next, len-2);

  if (end == NULL) return NULL;
  if(head->data == end->data)
  return end->next;
  else return NULL;
}

bool
palindrome (Node* head)
{
  if(head == NULL) return false;

  int len = 0;
  for(Node *p = head; p!=NULL; p=p->next)
    len++;

  if(len < 2) return true;

  Node* end = palindrome (head->next, len-2);

  if (end == NULL) return false;
  else return (head->data == end->data);
}

int
main()
{
  string input;
  cout << " Please input : ";
  getline (cin, input); 

  Node* head = newList(input);
  cout << " The linked list : " << head << endl;

  if(palindrome(head))
    cout << " This linked list is palindrome." << endl; 
  else
    cout << " This linked list is not palindrome." << endl;

  return 0;
}
