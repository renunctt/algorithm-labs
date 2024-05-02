#include <iostream>
using namespace std;

void replace(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

int *input_numbers(int length) {
  cout << "input numbers: ";
  int *n = new int[length];
  for (int i = 0; i < length; i++)
    cin >> n[i];
  return n;
}

void print_array(int *arr, int l) {
  for (int i = 0; i < l; i++)
    cout << arr[i] << ' ';
  cout << '\n';
}

int **input_matrix(int c, int r) {
  cout << "input matrix elem: ";
  int **m = new int*[c];
  for (int i = 0; i < c; i++)
    m[i] = new int[r];

  for (int i = 0; i < c; i++)
    for (int j = 0; j < r; j++)
      cin >> m[i][j];
  return m;
}

void print_matrix(int **m, int c, int r) {
  for (int i = 0; i < c; i++) {
    for (int j = 0; j < r; j++)
      cout << m[i][j] << ' ';
    cout << '\n';
  }
}

int main() {
  cout << "\n1 link func\n";
  cout << "(a, b): ";
  int a, b;
  cin >> a >> b;
  replace(a, b);
  cout << "(a, b): " << a << ' ' << b << '\n';

  cout << "\n2 array\n";
  cout << "input lenght: ";
  int n;
  cin >> n;
  int *nums = input_numbers(n);
  print_array(nums, n);

  cout << "\n3 matrix\n";
  cout << "inprt (col, row):\n";
  int c, r;
  cin >> r >> c;
  int **m = input_matrix(c, r);
  print_matrix(m, c, r);
}
