#include <bits/stdc++.h>

using namespace std;

int main() {
  int N; cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    int a; cin >> a;
    A[i] = a;
  }

  vector<int> dp;
  for (int i = N - 1; i > -1; --i) {
    auto it = upper_bound(dp.begin(), dp.end(), A[i]);
    if (it == dp.end()) {
      dp.push_back(A[i]);
    } 
    else *it = A[i];
  }

  cout << dp.size() << endl;
  return 0;
}
