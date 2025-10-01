#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll mod = 1e9 + 7;

int main() {
  int N, K; cin >> N >> K;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) cin >> A[i];
  vector<vector<ll>> dp(N + 1, vector<ll>(K + 1, 0));
  dp[N][K] = 1;

  for (int i = N - 1; i > -1; --i) {
    dp[i][0] = dp[i + 1][A[i]];
    for (int k = 1; k <= K; ++k) {
      if (k + A[i] <= K) {
        dp[i][k] = (dp[i + 1][k + A[i]] - dp[i + 1][k - 1] + mod) % mod;
      }
      else {
        dp[i][k] = (dp[i + 1][K] - dp[i + 1][k - 1] + mod) % mod;
      }
    }
    for (int k = 1; k <=K; ++k) {
      dp[i][k] = (dp[i][k] + dp[i][k - 1]) % mod;
    }
  }

  cout << (dp[0][0] + mod) % mod << endl;
  return 0;
}
