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
int FindEagle(int ar[ROW][COL], int r, int c, int r_count, int c_count,
              int size, int eagleCount);
int FindEagleSize();

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
  int arry[ROW][COL], row, col, num;

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
    cout << endl;

    cout << FindEagle(arry, row, col, 0, 0, 0, 0) << endl;
    cout << endl;
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

int FindEagle(int ar[ROW][COL], int r, int c, int r_count, int c_count,
              int size, int eagleCount) {
  if (r_count > r && c_count > c) {
    return eagleCount;
  }
  if (ar[r_count][c_count] > 0) {
    ar[r_count][c_count] = 0;
    size++;
    if (ar[r_count][c_count - 1] > 0 && r_count > 0 && c_count - 1 > 0) {
      ar[r_count][c_count] = 0;
      return FindEagle(ar, r , c, )
    }
    if (ar[r_count -1 ][c_count -1] > 0 && r_count -1 > 0 && c_count -1 > 0 &&
        r_count < r && c_count < c) {
      size++;
      c_count--;
      ar[r_count][c_count] = 0;
    }
    if (ar[r_count -1 ][c_count] > 0 && r_count > 0 && c_count > 0 &&
        r_count < r && c_count < c) {
      size++;
      c_count--;
      ar[r_count][c_count] = 0;
    }
  }
  if (ar[r_count][c_count] == 0 && c_count == c) {
    return FindEagle(ar, r, c, r_count++, 0, size, eagleCount);
  } else
    return FindEagle(ar, r, c, r_count, c_count++, size, eagleCount);
}