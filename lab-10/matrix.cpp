#include "matrix.h"
#include <iostream>

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

int matrix::summ_row(int col) {
  int res = 0;
  for (int i = 0; i < rows; ++i)
    res += data[col][i];
  return res;
}

int matrix::summ_col(int row) {
  int res = 0;
  for (int i = 0; i < cols; ++i)
    res += data[i][row];
  return res;
}

void matrix::println() {
  for (int i = 0; i < cols; ++i) {
    for (int j = 0; j < rows; ++j)
      std::cout << data[i][j] << ' ';
    std::cout << '\n';
  }
  std::cout << '\n';
}
