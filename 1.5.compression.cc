/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
//-------------------------------------------------
// compress string
// i.e. aabcccccaaa -> a2b1c5a3
//-------------------------------------------------
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void
compression(string & input)
{
  int len = 0; // calculate the length of compressed string
  int count = 1; // count the number of repeated characters

  for(int i=0; i<input.size(); i++)
  {
    if(i != input.size()-1 && input[i] == input[i+1])
    { // if input[i] is not the last one and is the same with next one
      count++;
    }
    else
    { // (log10(count)+1) calculate the length of interger string
      len += 1 + (int)(log10(count)+1);
      count = 1; // count start from 1
    }
  }

  // if the length of compressed string is no shorter than input
  if(len >= input.size()) return;

  // use a char array to store the compressed string
  char* str = new char[len + 1];

  count=1, len=0;
  for(int i=0; i<input.size(); i++)
  {
    if(i != input.size()-1 && input[i] == input[i+1])
    { // if input[i] is not the last one and is the same with next one
      count++;
    }
    else
    {  // copy the character first
      str[len++] = input[i];

      // then add the count to the char array
      int temp = pow(10, (int)(log10(count))); // temp = 100...
      while(temp>0)
      { // (count / 100...) % 10 get one number of the interger
        str[len++] = (count/temp) % 10 + 48; // '0' = 48
	temp /= 10; // get the next part
      }

      count = 1;
    }
  }

  str[len] = 0; // set the null terminator

  input = str;

  delete [] str;
}

int
main()
{
  string input;
  cout << " Please input  : ";
  getline (cin, input); //cin >> input;

  compression(input);
  cout << " compress input: " << input << endl; 

  //int value = 10000000;
  //cout << "size of " << value << "is " << (value == 0 ? 1 : (int)(log10(value)+1)) << endl;
  
  /*char str[10] = {};
  int count = 123456789;
  int len = 0;
  int m = pow(10, (int)(log10(count)));
  while(m>0)
  {
    str[len++] = (count / m) % 10 + 48; // '0' = 48
    m /= 10;
    cout << len-1 << ":" << m << ":" << str << endl;
  }
  str[len] = 0;
  cout << str << endl;*/

  return 0;
}
