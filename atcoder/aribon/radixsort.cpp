#include <iostream>
#include <vector>

using namespace std;
int getMax(const vector<int> &a) {
  int max_val = a[0];
  for (int i = 1; i < a.size(); ++i) {
    if (a[i] > max_val) {
      max_val = a[i];
    }
  }

  return max_val;
} 

void countSort(vector<int> &arr, int exp) {
  int n = arr.size();
  vector<int> output(n);
  vector<int> count(10, 0);

  for (int i = 0; i < n; ++i) {
    count[(arr[i] / exp) % 10]++;
  }

  for (int i = 1; i < 10; ++i) {
    count[i] += count[i-1];
  }

  for (int i = n - 1; i >= 0; --i) {
    output[count[(arr[i] / exp) % 10] - 1] = arr[i];
    count[(arr[i] / exp) % 10]--;
  }

  for (int i = 0; i < n; i++) {
   arr[i] = output[i];
  }
}

void radixSort(vector<int> arr) {
  int max_val = getMax(arr);
  for (int exp = 1; exp < max_val; exp*=10) {
    countSort(arr, exp);
  }
}
