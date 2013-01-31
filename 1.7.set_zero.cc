/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
//-------------------------------------------------
// in an matrix of M*N, if an element is 0
// set the entire row and column to 0
// i.e. 0 1 -> 0 0
//      3 2    0 2
//-------------------------------------------------
#include <iostream>
#include <string.h>
using namespace std;

void
setzero(int** matrix, const int m, const int n)
{
  if(m < 0 || n < 0) return;

  // cast the pointer-of-pointer to 2-dimensional-matrix pointer
  int(* mat)[n] = (int (*)[n]) matrix;

  // row[] and col[] is used to mark the line to be set zero
  bool row[m], col[n];
  memset(row, false, sizeof(bool) * m);
  memset(col, false, sizeof(bool) * n);

  // if an element is 0, mark the arrays
  for(size_t i=0; i<m; ++i)
  {
    for(size_t j=0; j<n; ++j)
    {
      if(mat[i][j] == 0)
      {
        row[i] = true;
	col[j] = true;
      }
    }
  }

  // set the row to 0 if row[] is 0
  for(size_t i=0; i<m; ++i)
    if(row[i])
      for(size_t j=0; j<n; ++j)
        mat[i][j] = 0;

  // set the col to 0 if col[] is 0
  for(size_t j=0; j<n; ++j)
    if(col[j])
      for(size_t i=0; i<m; ++i)
        mat[i][j] = 0;
}

int
main()
{
  const int m = 3;
  const int n = 4;
  int matrix[m][n] = {
                      {1, 2, 3, 4},
                      {5, 6, 7, 8},
		      {9, 0, 1, 2}
                     };

  //for(size_t i=0; i<n; ++i)
  //  for(size_t j=0; j<m; ++j)
  //    matrix[i][j] = (i + j) % 10;

  cout << " Input matrix: " << endl;
  for(size_t i=0; i<m; ++i)
  {
    cout << "                ";
    for(size_t j=0; j<n; ++j)
    {
      cout << " " << matrix[i][j];
    }
    cout << endl;
  }

  setzero((int **) matrix, m, n);

  cout << " Output matrix: " << endl;
  for(size_t i=0; i<m; ++i)
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
