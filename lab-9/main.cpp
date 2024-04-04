#include <iostream>
using namespace std;

int *input_nums(int length) {
  int i = 0;
  int *nums = new int[length];
  while (i < length)
    cin >> nums[i++];
  return nums;
}

void print_index(int index, int count) {
  if (index > -1)
    cout << "num index: " << index;
  else
    cout << "num not found";
  cout << "\nloop count: " << count << '\n';
}

void linear_search(int *nums, int length) {
  int search_num, i, count;
  int search_index = -1;
  i = count = 0;

  cout << "Linear search\ninput search num: ";
  cin >> search_num;

  while (i < length) {
    if (nums[i] == search_num) {
      search_index = i;
      break;
    }
    i = count = i + 1;
  }

  print_index(search_index, count);
}

void binary_search(int *nums, int length) {
  int search_num, i, count;
  int search_index = -1;
  int mid = length / 2;
  i = count = 0;

  cout << "Binary search\ninput search num: ";
  cin >> search_num;

  for (int i = 0; i < mid; i++, count++) {
    if (search_num > nums[mid])
      mid += mid / 2;
    else if (search_num < nums[mid])
      mid /= 2;
    else {
      search_index = mid;
      break;
    }
  }

  print_index(search_index, count);
}

int main() {
  int length;
  cin >> length;
  int *nums = input_nums(length);

  linear_search(nums, length);
  binary_search(nums, length);
}
