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
  cout << M.summ() << "\n\n";

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
  for (int i = 0; i < c; ++i, --r_index)
    for (int j = 0; j < r; ++j)
      reverse_row.at(r_index, j) = M.at(i, j);
  reverse_row.println();

  cout << "5. Reverse matrix col\n";
  matrix reverse_col(c, r);
  int c_index = r - 1;
  for (int i = 0; i < r; ++i, --c_index)
    for (int j = 0; j < c; ++j)
      reverse_col.at(j, c_index) = M.at(j, i);
  reverse_col.println();

  cout << "6. Matrix min row\n";
  for (int i = 0; i < c; ++i) {
    int min = M.at(i, 0);
    for (int j = 1; j < r; ++j)
      if (min > M.at(i, j))
        min = M.at(i, j);
    cout << min << '\n';
  }
  cout << '\n';

  cout << "7. Matrix max col\n";
  for (int i = 0; i < r; ++i) {
    int max = M.at(0, i);
    for (int j = 0; j < c; ++j)
      if (max < M.at(j, i))
        max = M.at(j, i);
    cout << max << ' ';
  }
  cout << "\n\n";

  cout << "8. Diagonal summ\n";
  int summ, d;
  summ = d = 0;
  for (int i = 0; i < c; ++i, ++d)
    for (int j = 0; j < r; ++j)
      if (d == j)
        summ += M.at(i, j);
  cout << summ << "\n\n";

  cout << "9. Scope diagonal summ\n";
  summ = 0;
  d = r - 1;
  for (int i = 0; i < c; ++i, --d)
    for (int j = 0; j < r; ++j)
      if (d == j)
        summ += M.at(i, j);
  cout << summ << "\n\n";

  cout << "10. Matrix transporter\n";
  matrix transporter_m(r, c);
  for (int i = 0; i < c; ++i)
    for (int j = 0; j < r; ++j)
      transporter_m.at(j, i) = M.at(i, j);
  transporter_m.println();
}
