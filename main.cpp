#include "parameters.h"
#include <cassert>
#include <fstream>
#include <iostream>

using namespace std;
const int ROW = 50;
const int COL = 50;
int fib(int n);
int sum(int n);
int findLargest(const int arry[], int size, int largest);
int FindEagle(int ar[ROW][COL], int r, int c, int r_count, int c_count , int e_size);

int main() {

  cout << "Fibonacci number for the " << FibVal << "th term is " << fib(FibVal)
       << ".\n";
  cout << endl;

  cout << "The sum of 1 to " << SumVal << " is " << sum(SumVal) << ".\n";
  cout << endl;

  int size = (sizeof(LongestVal) / sizeof(LongestVal[0]));

  cout << "The largest number in the array is "
       << LongestVal[findLargest(LongestVal, size - 1, 12)];
  cout << endl << endl;

  ifstream myIn;
  int arry[ROW][COL], row, col, num, eagles = 0;

  myIn.open("eagle.dat");
  assert(myIn);

  while (myIn >> row >> col) {

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        myIn >> num;
        arry[i][j] = num;
      }
    }

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        cout << arry[i][j] << " ";
      }
      cout << endl;
    }
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (arry[i][j] > 0) {
          FindEagle(arry, row, col, i, j,0);
        }
      }
    }
  }

  myIn.close();

  return 0;
}

int fib(int n) {
  if (n == 0)
    return 0;
  else if (n == 1 || n == 2)
    return 1;
  else
    return fib(n - 2) + fib(n - 1);
}

int sum(int n) {

  if (n == 1)
    return 1;
  else
    return sum(n - 1) + n;
}

int findLargest(const int arry[], int size, int largest) {
  size--;
  if (size < 0)
    return largest;
  if (arry[largest] > arry[size]) {
    return findLargest(arry, size, largest);
  } else {
    largest = size;
    return findLargest(arry, size, largest);
  }
}

int FindEagle(int ar[ROW][COL], int r, int c, int r_count, int c_count , int e_size) {
  
  ar[r_count][c_count]=0;

  if(ar[r_count][c_count] == 0 && )
  
}