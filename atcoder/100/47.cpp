#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int main() {
  int N; cin >> N;
  vector<ll> A(2 * N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
    A[i + N] = A[i];
  }

  vector<vector<ll>> dp(2 * N, vector<ll>(2 * N, 0));
  for (int i = 0; i < N; ++i) {
    dp[i][i] = A[i];
    dp[i + N][i + N] = A[i + N];
  }
  for (int l = 2; l <= N; ++l) {
    for (int i = 0; i < 2 * N - l; ++i) {
      int j = i + l - 1;
      if (l % 2) {
        //JOIの番
        dp[i][j] = max(dp[i][j], dp[i+1][j] + A[i]);
        dp[i][j] = max(dp[i][j], dp[i][j - 1] + A[j]);
      }
      else {
        //IOIの番
        if (j + 1 < 2 * N && (A[i] > A[j + 1] || l == N)) {
          dp[i][j] = max(dp[i][j], dp[i + 1][j]);
        }
        if (i - 1 >= 0 && (A[i - 1] < A[j] || l == N)) {
          dp[i][j] = max(dp[i][j], dp[i][j-1]);
        }
      }
    }
  }
  ll res = 0;
  for (int i = 0; i < N; ++i) {
    res = max(res, dp[i][i + N - 1]);
  }
  cout << res << endl;
  return 0;
}
