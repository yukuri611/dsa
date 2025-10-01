#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<vector<ll>> A(N, vector<ll>(N));
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j) cin >> A[i][j];

  vector<ll> groupScore((1 << N), 0);
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      for (int mask = 0; mask < (1 << N); ++mask) {
        if ((mask >> i) & 1 && (mask >> j) & 1) groupScore[mask] += A[i][j];
      }
    }
  }

  vector<ll> dp((1 << N), 0);
  for (int s = 0; s < (1 << N); ++s) {
    for (int t = s; t > 0; t = (t - 1) & s) {
      int u = s ^ t;
      dp[s] = max(dp[s], groupScore[t] + dp[u]);
    }
  }

  cout << dp[(1 << N) - 1] << endl;
  return 0;
}
