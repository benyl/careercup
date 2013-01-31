/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
//-------------------------------------------------
// check if a string is a rotation of another string
// using only one call to function isSubstring
// i.e. "hello" is a rotation of "elloh"
//-------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

bool
isSubstring(string a, string b)
{
  // find if b is a substring of a
  return a.find(b) != string::npos;
}

bool
rotation(string a, string b)
{
  // if the length is different, can not be permutation
  if(a.size() != b.size()) return false;

  string aa = a + a; // aa is double of a

  // if b is substring of aa, b is a rotation of a
  return isSubstring(aa, b);
}

int
main()
{
  string str1, str2;
  cout << " Please input string 1: ";
  getline (cin, str1); //cin >> input;
  cout << " Please input string 2: ";
  getline (cin, str2); //cin >> input;

  if(rotation(str1, str2))
    cout << " string 1 is a rotation of string 2." << endl; 
  else
    cout << " string 1 is not a rotation of string 2." << endl;

  return 0;
}
