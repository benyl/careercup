/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
//-------------------------------------------------
// find the begining node of a loop linked list
// i.e. input : A -> B -> C -> D -> E -> C (loop back to c)
//      output: C
//-------------------------------------------------
// Execution result:
//
// Please input : ABCDEC
// The linked list  : A -> B -> C -> D -> E
//                              ^---------|
// The loop start at: C
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

// construct new circular linked list
Node*
newLoopList(string str, int& k) {

  Node* head = NULL, *end = NULL;
  k = 0;

  if(str.size() <2) return NULL;
  
  for(int i=0; i<str.size()-1; i++)
  {
    Node* p = new Node(str[i], NULL);
    if(i == 0) head = p;
    else end->next = p;

    end=p;
  }
  
  for(Node *p = head; p!=NULL; p=p->next)
  {
    if(p->data == str[str.size()-1]) 
    {
      end->next = p;
      break;
    }
    k++;
  }

  if(k == str.size()-1)
  {
    Node *p = new Node(str[str.size()-1], NULL);
    p->next = p;
    end->next = p;
  }

  return head;
}

Node*
findLoopEntry(Node* head) {
  if(head == NULL) return NULL;

  // p runs 1 step a time, q runs 2 steps a time
  Node* p=head, *q=head->next;

  if(p == q) return p;
  p=p->next;
  q=q->next;
  if(p == q) return p;
  q=q->next;
  if(p == q) return p;
  
  while(p!=q)
  {
    p=p->next;
    if(p == q) return p; // p catch up with q
    q=q->next;
    if(p == q) break;
    q=q->next;
  }

  p = head;
  while(p!=q)
  {
    q=q->next;
    if(p == q) break;
    p=p->next;
  }

  return p;
}



int
main()
{
  string input;
  int k;
  cout << " Please input : ";
  getline (cin, input); 

  Node* head = newLoopList(input, k);
  Node *p = head;

  if(head == NULL)
  {
    cout << " no enough information!" << endl;
    return 0;
  }

  cout << " The linked list  : ";
  for(int i=0; i<input.size(); i++)
  {
    cout << p->data;
    p = p->next;

    if(i == input.size()-2 && k < input.size()-1) break;
    else cout << (i < (input.size()-1) ? " -> " : "");
  }
  cout << endl;

  cout << "                    ";
  for(int i=0; i<input.size(); i++)
  {
    if(i == k && (k == input.size()-1 || k == input.size()-2))
     {cout << "^"; break;}
    else if(i == input.size()-2 && k < input.size()-1)
     {cout << "|"; break;}
    else if(i<k)  cout << "     ";
    else if(i==k) cout << "^----";
    else          cout << "-----";
  }
  cout << endl;

  p = findLoopEntry(head);
  cout << " The loop start at: " << p->data << endl;

  return 0;
}
