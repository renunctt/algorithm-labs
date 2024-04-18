#include "utilities.h"
#include <iostream>

void sort(int *array, int length) {
  for (int i = 0; i < length - 1; ++i)
    for (int j = i + 1; j < length; ++j)
      if (array[i] > array[j]) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
}

void print_array(int *array, int length) {
  for (int i = 0; i < length; ++i)
    std::cout << array[i] << ' ';
  std::cout << "\n\n";
}
