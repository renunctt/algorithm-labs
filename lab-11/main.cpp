#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits>
#include <string>
using namespace std;

int input_length() {
  cout << "input length: ";
  int n;
  cin >> n;
  return n;
}

int *input_numbers(int length) {
  cout << "input numbers: ";
  int *n = new int[length];
  for (int i = 0; i < length; i++)
    cin >> n[i];
  return n;
}

int summ_numbers(int *numbers, int length) {
  int res = 0;
  for (int i = 0; i < length; i++)
    res += numbers[i];
  return res;
}

int max_numbers(int *numbers, int length) {
  int m = numbers[0];
  for (int i = 1; i < length; i++)
    if (m < numbers[i])
      m = numbers[i];
  return m;
}

int min_numbers(int *numbers, int length) {
  int m = numbers[0];
  for (int i = 1; i < length; i++)
    if (m > numbers[i])
      m = numbers[i];
  return m;
}

string isprime(int number) {
  if (number <= 1)
    return "no";
  for (int i = 2; i * i <= number; ++i)
    if (number % i == 0)
      return "no";
  return "yes";
}

void sort_numbers(int *numbers, int length) {
  for (int i = 0; i < length - 1; ++i) {
    for (int j = 0; j < length - i - 1; ++j) {
      if (numbers[j] > numbers[j + 1]) {
        int temp = numbers[j];
        numbers[j] = numbers[j + 1];
        numbers[j + 1] = temp;
      }
    }
  }
}

void print_numbers(int *numbers, int length) {
  for (int i = 0; i < length; i++)
    cout << numbers[i] << ' ';
  cout << '\n';
}

int average_number(int *numbers, int length) {
  double summ = 0;
  for (int i = 0; i < length; i++)
    summ += numbers[i];
  return summ / length;
}

string ispalindrom(string &str) {
  int i = 0;
  int j = str.length() - 1;

  while (i < j) {
    while (!isalnum(str[i]) && i < j)
      ++i;
    while (!isalnum(str[j]) && i < j)
      --j;

    if (tolower(str[i]) != tolower(str[j]))
      return "no";

    ++i;
    --j;
  }
  return "yes";
}

int *random_numbers(int length) {
  int *n = new int[length];
  srand(time(nullptr));
  for (int i = 0; i < length; ++i)
    n[i] = 1 + rand() % (100 - 1 + 1);
  return n;
}

int find_median(int *numbers, int length) {
  if (length % 2 != 0)
    return numbers[length / 2];
  int mid = length / 2;
  return (numbers[mid - 1] + numbers[mid]) / 2.0;
}

int iseven_numbers_count(int *numbers, int length) {
  int res = 0;
  for (int i = 0; i < length; i++)
    if (numbers[i] % 2 == 0)
      res++;
  return res;
}

int* remove_duplicates(int *numbers, int length, int& newlen) {
    int unique = 1;
    for (int i = 1; i < length; ++i)
        if (numbers[i] != numbers[i - 1])
            ++unique;

    int* n = new int[unique];
    n[0] = numbers[0];
    int index = 1;
    for (int i = 1; i < length; ++i)
        if (numbers[i] != numbers[i - 1])
            n[index++] = numbers[i];

    newlen = unique;
    return n;
}

int main() {
  cout << "\n1 Task. summ numbers\n";
  int l1 = input_length();
  int *nums1 = input_numbers(l1);
  cout << summ_numbers(nums1, l1) << '\n';

  cout << "\n2 Task. max & min numbers\n";
  cout << "max: " << max_numbers(nums1, l1) << '\n';
  cout << "min: " << min_numbers(nums1, l1) << '\n';

  cout << "\n3 Task. is number prime\n";
  int number;
  cout << "input number: ";
  cin >> number;
  cout << isprime(number) << '\n';

  cout << "\n4 Task. sort numbers\n";
  int l2 = input_length();
  int *nums2 = input_numbers(l2);
  sort_numbers(nums2, l2);
  print_numbers(nums2, l2);

  cout << "\n5 Task. average number\n";
  int l3 = input_length();
  int *nums3 = input_numbers(l3);
  cout << average_number(nums3, l3) << '\n';

  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << "\n6 Task. is palindrom\n";
  string str;
  getline(cin, str);
  cout << ispalindrom(str) << '\n';

  cout << "\n7 Task. random numbers\n";
  int l4 = input_length();
  int *nums4 = random_numbers(l4);
  print_numbers(nums4, l4);

  cout << "\n8 Task. find median\n";
  int l5 = input_length();
  int *nums5 = input_numbers(l5);
  sort_numbers(nums5, l5);
  cout << find_median(nums5, l5) << '\n';

  cout << "\n9 Task. is even count in numbers\n";
  int l6 = input_length();
  int *nums6 = input_numbers(l6);
  cout << iseven_numbers_count(nums6, l6) << '\n';

  cout << "\n10 Task. remove duplicates\n";
  int l7 = input_length();
  int *nums7 = input_numbers(l7);
  int l8;
  int *nums8 = remove_duplicates(nums7, l7, l8);
  print_numbers(nums8, l8);
}
