#include <bits/stdc++.h>

using namespace std;

int LIS(vector<int> &C) {
  vector<int> dp;
  for (int c: C) {
    auto it = upper_bound(dp.begin(), dp.end(),c);
    if (it == dp.end()) dp.push_back(c);
    else *it = c;
  }
  return dp.size();
}

int main() {
  int N; cin >> N;
  vector<int> C(N);
  for (int i = 0; i < N; ++i) {
    cin >> C[i];
  }

  int res = N - LIS(C);
  cout << res << endl;
  return 0;
}
