#include "matrix.h"
#include "utilities.h"
#include <iostream>
using namespace std;

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
  print_array(rows_summ, c);

  cout << "3. Sort matrix by col summ\n";
  int *cols_summ = new int[r];
  for (int i = 0; i < r; ++i)
    cols_summ[i] = M.summ_col(i);
  sort(cols_summ, r);
  print_array(cols_summ, r);

  cout << "4. Reverse matrix row\n";
  matrix reverse_row(c, r);
  int r_index = c - 1;
  for (int index = 0; index < c; ++index, --r_index)
    for (int j = 0; j < r; ++j)
      reverse_row.at(r_index, j) = M.at(index, j);
  reverse_row.println();
}
