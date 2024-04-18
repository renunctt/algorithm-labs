#ifndef MATRIX_H
#define MATRIX_H

class matrix {
private:
  int **data;
  int cols, rows;

public:
  matrix(int cols, int rows);
  int &at(int col, int row);
  ~matrix();
  int summ();
  int summ_row(int row);
};

#endif
