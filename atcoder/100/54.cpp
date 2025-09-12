#include <bits/stdc++.h>

using namespace std;

int LIS(vector<int> C) {
  vector<int> L;
  for (int c: C) {
    auto it = lower_bound(L.begin(), L.end(), c);
    if (it == L.end()) L.push_back(c);
    else *it = c;
  }
  return L.size();
}

int main() {
  int N; cin >> N;
  vector<int> C(N);
  for (int i = 0;i < N; ++i) {
    cin >> C[i];
  }
  int res = N - LIS(C);
  cout << res << endl;
  return 0;
}
