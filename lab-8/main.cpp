#include <iostream>
using namespace std;

int summ(int *nums, int size) {
  int res = 0;
  for (int i = 0; i < size; i++)
    res += nums[i];
  return res;
}

int max(int *nums, int size) {
  int max = nums[0];
  for (int i = 1; i < size; i++) {
    max = max > nums[i] ? max : nums[i];
  }
  return max;
}

int min(int *nums, int size) {
  int min = nums[0];
  for (int i = 1; i < size; i++) {
    min = min < nums[i] ? min : nums[i];
  }
  return min;
}

string search(int *nums, int size, int searchnum) {
  for (int i = 0; i < size; i++) {
    if (nums[i] == searchnum)
      return "yes";
  }
  return "no";
}

int count(int *nums, int size) {
  int count = 0;
  for (int i = 0; i < size; i++) {
    if (nums[i] > 0)
      count++;
  }
  return count;
}

int midnum(int *nums, int size) { return float(summ(nums, size)) / size; }

int searchindex(int *nums, int size, int searchnum) {
  for (int i = 0; i < size; i++) {
    if (nums[i] == searchnum)
      return i;
  }
  return -1;
}

string examination_nums(int *nums, int size) {
  string res;
  int temp = nums[0];
  for (int i = 1; i < size; i++) {
    if (temp < nums[i]) {
      temp = nums[i];
      res = "Возрастание";
      continue;
    }
    res = "no";
    break;
  }
  if (res != "no")
    return res;
  for (int i = 1; i < size; i++) {
    if (temp > nums[i]) {
      temp = nums[i];
      res = "Убывание";
      continue;
    }
    res = "no";
    break;
  }
  return res;
}

int summ_positive(int *nums, int size) {
  int summ = 0;
  for (int i = 0; i < size; i++) {
    if (nums[i] > 0)
      summ += nums[i];
  }
  return summ;
}

int remove_duplicates(int *nums, int size) {
  int index = 0;

  for (int i = 0; i < size; ++i) {
    bool duplicate = false;
    for (int j = 0; j < index; ++j) {
      if (nums[i] == nums[j]) {
        duplicate = true;
        break;
      }
    }
    if (!duplicate) {
      nums[index] = nums[i];
      ++index;
    }
  }

  return index;
}

void print_array(int *nums, int size) {
  for (int i = 0; i < size; i++) {
    cout << nums[i] << ' ';
  }
  cout << '\n';
}

int main() {
  int size, n;
  cin >> size;
  int *nums = new int[size];
  for (int i = 0; i < size; i++) {
    cin >> nums[i];
  }

  cout << summ(nums, size) << '\n';
  cout << max(nums, size) << '\n';
  cout << min(nums, size) << '\n';

  cin >> n;
  cout << search(nums, size, n) << '\n';
  cout << count(nums, size) << '\n';
  cout << midnum(nums, size) << '\n';
  cin >> n;
  cout << searchindex(nums, size, n) << '\n';
  cout << examination_nums(nums, size) << '\n';
  cout << summ_positive(nums, size) << '\n';
  print_array(nums, size);

  int new_size = remove_duplicates(nums, size);

  print_array(nums, new_size);

  return 0;
}
