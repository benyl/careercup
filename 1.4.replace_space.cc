/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
//-------------------------------------------------
// replace the space with "%20"
// i.e. "Mr John Smith" -> "Mr%20John%20Smith"
//-------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

void
replace(string & input)
{
  int len = input.size() + 1; // the string size + "\0"

  // calculate the length of string after replacement
  // new length = origin length + space number * 2
  for(size_t i=0; i<input.size(); i++)
    if(input[i] == ' ') len += 2;

  char* str = new char[len];

  // copy the string to char array and repalce space
  int i=0, j=0;
  while(i<input.size())
  {
    if(input[i] == ' ')
    { // replace ' ' with '%20'
      str[j++] = '%';
      str[j++] = '2';
      str[j++] = '0';
      i++;
    }
    else
    { // copy the other characters
      str[j++] = input[i++];
    }
  }
  
  str[len-1] = 0; // add the null terminator

  input = str;

  delete [] str;
}

int
main()
{
  string input;
  cout << " Please input : ";
  getline (cin, input); //cin >> input;

  replace(input);
  cout << " replace input: " << input << endl; 

  return 0;
}
