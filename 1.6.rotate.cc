/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
//-------------------------------------------------
// rotate a matrix by 90 degrees
// i.e. 1 2 -> 4 1
//      3 4    3 2
//-------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

void
rotate(int** matrix, const int n)
{
  if(n < 2) return; // matrix should not be smaller than 2*2

  // cast the pointer-of-pointer to 2-dimensional-matrix pointer
  int(* mat)[n] = (int (*)[n]) matrix;

  int col = (n + n%2) / 2; // if n is odd, col=(n+1)/2, else col=n/2
  int row = (n - n%2) / 2; // if n is odd, row=(n-1)/2, else row=n/2

  // rotate the matrix by 90 degrees in the block of col * row
  for(size_t i=0; i<row; ++i)
  {
    for(size_t j=0; j<col; ++j)
    {
      int temp          = mat[n-1-j][i];
      mat[n-1-j][i]     = mat[n-1-i][n-1-j];
      mat[n-1-i][n-1-j] = mat[j][n-1-i];
      mat[j][n-1-i]     = mat[i][j];
      mat[i][j]         = temp;
    }
  }
}

int
main()
{
  const int n = 4;
  int matrix[n][n] = {
                      {1, 2, 3, 0},
                      {4, 5, 6, 0},
		      {7, 8, 9, 0},
		      {0, 0, 0, 0}
                     };

  //for(size_t i=0; i<n; ++i)
  //  for(size_t j=0; j<n; ++j)
  //    matrix[i][j] = (i + j) % 10;

  cout << " Input matrix: " << endl;
  for(size_t i=0; i<n; ++i)
  {
    cout << "                ";
    for(size_t j=0; j<n; ++j)
    {
      cout << " " << matrix[i][j];
    }
    cout << endl;
  }

  rotate((int **) matrix, n);

  cout << " rotated matrix: " << endl;
  for(size_t i=0; i<n; ++i)
  {
    cout << "                ";
    for(size_t j=0; j<n; ++j)
    {
      cout << " " << matrix[i][j];
    }
    cout << endl;
  }

  return 0;
}
