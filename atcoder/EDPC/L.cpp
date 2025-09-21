#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  int N; cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }

  vector<vector<ll>> dp(N + 1, vector<ll>(N + 1));
  for (int i = 0; i < N; ++i) {
    dp[i][i] = 0;
  }
  for (int l = 1; l <= N; ++l) {
    for (int i = 0; i <= N-l; ++i) {
      int j = i + l;
      if ((N - l) % 2 == 0) {
        // xの番
        dp[i][j] = dp[i + 1][j] + A[i];
        dp[i][j] = max(dp[i][j], dp[i][j - 1] + A[j-1]);
      }
      else {
        // yの番
        dp[i][j] = dp[i + 1][j] - A[i];
        dp[i][j] = min(dp[i][j], dp[i][j - 1] - A[j-1]);
      }
    }
  }

  cout << dp[0][N] << endl;
  return 0;
}
