#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
  int n; cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; ++i) cin >> A[i];
  int q; cin >> q;
  vector<int> m(q);
  for (int i = 0; i < q; ++i) cin >> m[i];

  unordered_set<int> possible_sums;

  //bit 探索
  for (int j = 0; j < (1 << n); ++j) {
    int bit[n];
    for (int k = 0; k < n; ++k) {
      int div = 1 << k;
      bit[n - 1 - k] = (j / div) % 2;
    }
    int total = 0;
    for (int i = 0; i < n; ++i) {
      if (bit[i]) total += A[i];
    }
    possible_sums.insert(total);
  }

  for (int m_i: m) {
    if(possible_sums.count(m_i)) {
      cout << "yes" << endl;
    }
    else {
      cout << "no" << endl;
    }
  }
  return 0;
  
}
