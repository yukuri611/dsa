#include <bits/stdc++.h>

using namespace std;

int main() {
  int n; cin >> n;
  vector<int> C(n), R(n);
  for (int i = 0; i < n; ++i) cin >> C[i] >> R[i];

  vector<vector<int>> dp(n, vector<int>(n, INT_MAX)); //dp[i][j] = iからjをかけるときの最小値
  for (int i = 0; i < n; ++i) dp[i][i] = 0;
  for (int l = 2; l <= n; ++l) {
    for (int i = 0; i <= n - l; ++i) {
      int j = i + l - 1;
      for (int k = i; k < j; ++k) {
        int temp = dp[i][k] + dp[k + 1][j] + C[i] * R[k] * R[j];
        dp[i][j] = min(dp[i][j], temp); 
      }
    }
  }

  cout << dp[0][n-1] << endl;
  return 0;
}
