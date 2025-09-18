#include <bits/stdc++.h>

using namespace std;

int main() {
  int N; cin >> N;
  vector<int> A(N);
  set<int> setA;
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
    setA.insert(A[i]);
  }
  vector<int> uniqueA(setA.begin(), setA.end());
  sort(uniqueA.begin(), uniqueA.end());
  vector<int> res(N);
  for (int i = 0; i < N; ++i) {
    int k = lower_bound(uniqueA.begin(), uniqueA.end(), A[i]) - uniqueA.begin();
    res[i] = k;
  }
  for (int r: res) cout << r << endl;
  return 0;
}
