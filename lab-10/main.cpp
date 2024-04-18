#include "matrix.h"
#include <iostream>
using namespace std;

void sort(int *array, int length) {
  for (int i = 0; i < length - 1; ++i)
    for (int j = i + 1; j < length; ++j)
      if (array[i] > array[j]) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
}

int main() {
  int c, r;
  cin >> c >> r;
  matrix M(c, r);

  for (int i = 0; i < c; ++i)
    for (int j = 0; j < r; ++j)
      cin >> M.at(i, j);

  cout << "1. Summ matrix\n";
  cout << M.summ() << '\n';

  cout << "2. Sort matrix by row summ\n";
  int *rows_summ = new int[c];
  for (int i = 0; i < c; ++i)
    rows_summ[i] = M.summ_row(i);
  sort(rows_summ, c);
  for (int i = 0; i < c; ++i)
    cout << rows_summ[i] << ' ';
  cout << '\n';
}
