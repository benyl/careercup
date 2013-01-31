/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
//-------------------------------------------------
// reverse a null-terminated string in c/c++
// i.e. "abcde" -> "edcba"
//----------------------------------------------
#include <iostream>
#include <cstring>
using namespace std;

void
reverse(char* str)
{
  size_t i = 0, j = 0;

  while(str[i]!=0) ++i; // go to the end of string "\0"
  --i; // move to the charcter before "\0"

  while(i>j) // swap the head and end characters one by one
  { // xor swap
    str[i] ^= str[j];     // a = a xor b
    str[j] ^= str[i];     // b = b xor (a xor b) = a
    str[i--] ^= str[j++]; // a = (a xor b) xor a = b
  }

  return;
}

int
main()
{
  string input;
  cout << " Please input : ";
  getline (cin, input);

  char* str = new char[input.size() + 1]; // the string size + "\0"
  strcpy(str, input.c_str());

  reverse(str);
  cout << " reverse input: " << str << endl;

  delete [] str;
  return 0;
}
