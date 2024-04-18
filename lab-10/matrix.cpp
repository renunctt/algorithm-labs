#include "matrix.h"

matrix::matrix(int cols, int rows) {
  this->cols = cols;
  this->rows = rows;
  data = new int *[cols];
  for (int i = 0; i < cols; ++i)
    data[i] = new int[rows]();
}

matrix::~matrix() {
  for (int i = 0; i < cols; ++i)
    delete[] data[i];
  delete[] data;
}

int &matrix::at(int col, int row) { return data[col][row]; }

int matrix::summ() {
  int res = 0;
  for (int i = 0; i < cols; ++i)
    for (int j = 0; j < rows; ++j)
      res += data[i][j];
  return res;
}
