/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
//-------------------------------------------------
// Partition a linked list around X so that 
// all nodes smaller than X go before all nodes bigger or equal than X
// i.e. input : 6->8->3->2->5, X = 4
//      output: 3->2->6->8->5
//-------------------------------------------------
// Execution result:
//
// Please input : 68325
// Input the number of node to partition: 4
// The linked list : 6 -> 8 -> 3 -> 2 -> 5
// Partition around 4 : 3 -> 2 -> 6 -> 8 -> 5
//-------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

typedef int Data;

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
    Node* p = new Node(str[i] - 48, head);
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
partition (Node *& head, int x)
{
  if(head == NULL) return;

  // last is use to point to the last element that is smaller than X
  // runner is use to find the next element that is smaller than X
  Node* last = NULL, *runner = head, *pre=NULL;

  // partition the linked list around x
  while(runner!= NULL)
  {
    if(runner->data < x)
    {
      if(last == NULL) // this is the first element smaller than X
      {
         if(runner == head)
         {
           last = head;
           pre = runner;
           runner = runner->next;
         }
         else
         { // move the element to the head
           pre->next = runner->next;
           runner->next = head;
           head = runner;
           // point the last to head
           last = head;
           runner = pre->next;
         }
      } // END: if(runner == head)
      else 
      if(runner == last->next)
      {  // if runner == last->next, move both forward
         last = last->next;
         pre = runner;
         runner = runner->next;
      }
      else
      {  // remove it from the linked list
         pre->next = runner->next;
         // move the element after last
         runner->next = last->next;
         last->next = runner;
         // point the last to next
         last = last->next;
         runner = pre->next;
      } // END: if(runner == last)
    }
    else
    {
      pre = runner;
      runner = runner->next;
    } //END: if(runner->data < X)
  } //END: while(runner!= NULL)
}


int
main()
{
  string input;
  int x;
  cout << " Please input : ";
  getline (cin, input); 
  cout << " Input the number of node to partition: ";
  cin >> x; 

  // construct new array
  Node* head = newList(input);
  cout << " The linked list : " << head << endl;

  partition(head, x);

  cout << " Partition around " << x << " : " << head << endl;

  return 0;
}
