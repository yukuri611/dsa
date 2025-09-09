#include <bits/stdc++.h>

using namespace std;

int main() {
  int N; cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) cin >> A[i];

  using LL = long long;
  vector<LL> sum(N + 1); //sum[i] = 0 ~ i-1までの総和
  sum[0] = 0;
  for (int i = 1; i < N + 1; ++i) {
    sum[i] = sum[i-1] + A[i-1];
  }
  for (int k = 1; k < N + 1; ++k) {
    LL res = 0;
    for (int i = 0; i + k <= N; ++i) {
      res = max(res, sum[i + k] - sum[i]);
    }
    cout << res << endl;
  }
  return 0;
}
