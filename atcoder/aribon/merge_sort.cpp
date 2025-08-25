#include <iostream>
#include <vector>

using namespace std;

void merge_sort(vector<int> &a, int l, int r) {
  //lからrまでのaの要素を昇順でソートする
  
  // base_case
  if (r == l) {
    return;
  }
  int mid = l + (r - l) / 2;

  merge_sort(a, l, mid);
  merge_sort(a, mid + 1, r);

  vector<int> buf;
  for (int i = l; i < mid + 1; ++i) {
    buf.push_back(a[i]);
  }
  for (int i = r; i > mid; --i) {
    buf.push_back(a[i]);
  }

  int left_pointer = 0, right_pointer = buf.size()-1;
  for (int i = l; i <= r; i++) {
    if(buf[left_pointer] <= buf[right_pointer]) {
      a[i] = buf[left_pointer++];
    }
    else {
      a[i] = buf[right_pointer--];
    }
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  merge_sort(a, 0, n-1);

  for (int i = 0; i < n; ++i) {
    cout << a[i] << " ";
  }
  cout << endl;
  return 0;
}

