#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll mod = 1e9 + 7;

int main() {
  int N;
  cin >> N;
  string s;
  cin >> s;

  vector<vector<ll>> dp(
      N,
      vector<ll>(
          N,
          0));  // dp[i][j] = 以下の0~jまでの累積和。0 ~
                // iまでのボールを挿入した状態で、i-1番目のボールがインデックスjにいる組み合わせ
  for (int j = 0; j <= N; ++j) dp[0][0] = 1;
  for (int i = 1; i < N; ++i) {
    if (s[i - 1] == '<') {
      dp[i][0] = 0;
      for (int j = 1; j <= i; ++j) {
        dp[i][j] = dp[i - 1][j - 1];
      }
    } else {
      dp[i][0] = dp[i - 1][i - 1];
      for (int j = 1; j < i; ++j) {
        dp[i][j] = (dp[i - 1][i - 1] - dp[i - 1][j - 1] + mod) % mod;
      }
    }
    for (int j = 1; j < N; ++j) {
      dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
    }
  }

  cout << dp[N - 1][N - 1] << endl;
  return 0;
}
