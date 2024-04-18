#include "matrix.h"
#include <iostream>
using namespace std;

int main() {
  int c, r;
  cin >> c >> r;
  matrix M(c, r);

  for (int i = 0; i < c; ++i)
    for (int j = 0; j < r; ++j)
      cin >> M.at(i, j);

  cout << M.summ() << '\n';
}
