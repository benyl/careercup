/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
//-------------------------------------------------
// decide if one string is a permutation of another string
// i.e. "hello" is a permuataion of "oellh"
//-------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

bool
permutation(string a, string b)
{
  // if the length is different, can not be permutation
  if(a.size() != b.size()) return false;

  /*
  // use idea of Bucket-sort to remember every ASCII character
  int bucket_a[256] = {}; 
  int bucket_b[256] = {};
  int num_a = 0, num_b = 0;

  for(size_t i=0; i<a.size(); ++i)
  {
    if(bucket_a[a[i]]++ == 0) num_a++;
    if(bucket_b[b[i]]++ == 0) num_b++;
  }

  if(num_a != num_b) return false;

  for(size_t i=0; i<a.size(); ++i)
  {
    if(bucket_a[a[i]] != bucket_b[a[i]]) return false;
  }*/

  // use idea of Bucket-sort to count every ASCII character
  int bucket[256] = {};

  // count the apprear time of every character in a
  for(size_t i=0; i<a.size(); i++)
    bucket[a[i]]++; 

  // the appear time of character in b shold be the same with a
  for(size_t i=0; i<b.size(); i++)
    if(bucket[b[i]]-- == 0) return false;

  return true;
}

int
main()
{
  string str1, str2;
  cout << " Please input string 1: ";
  getline (cin, str1); //cin >> input;
  cout << " Please input string 2: ";
  getline (cin, str2); //cin >> input;

  if(permutation(str1, str2))
    cout << " string 1 is a permutation of string 2." << endl; 
  else
    cout << " string 1 is not a permutation of string 2." << endl;

  return 0;
}
