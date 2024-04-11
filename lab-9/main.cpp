#include <iostream>
using namespace std;

int length = 0;

int *input_nums() {
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

void linear_search(int *nums) {
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

void binary_search(int *nums) {
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

  cout << search_index << '\n';

  print_index(search_index, count);
}

void max_elem(int *nums) {
  int max, index, i = 1;
  index = 0;
  max = nums[0];
  while (i < length) {
    if (max < nums[i++]) {
      max = nums[i];
      index = i;
    }
  }
  cout << "max number: " << max << " index: " << index << '\n';
}

void min_elem(int *nums) {
  int min, index, i = 1;
  index = 0;
  min = nums[0];
  while (i < length) {
    if (min > nums[i++]) {
      min = nums[i];
      index = i;
    }
  }
  cout << "min number: " << min << " index: " << index << '\n';
}

void isNumsSimetria(int *nums) {
  int start, end = length - 1;
  start = 0;
  while (start < end)
    if (nums[start++] != nums[end--]) {
      cout << "no\n";
      return;
    }
  cout << "yes\n";
}

void print_nums_index(int *nums) {
  int i = 0;
  while (i < length)
    cout << "index: " << i << " number: " << nums[i++] << '\n';
}

int main() {
  cin >> length;
  int *nums = input_nums();

  linear_search(nums);

  // Работает только с сортированном массивом
  binary_search(nums);

  max_elem(nums);
  min_elem(nums);
  isNumsSimetria(nums);
  print_nums_index(nums);
  cout << "min index: 0 number: " << nums[0] << '\n';
}
