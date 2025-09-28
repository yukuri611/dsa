#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll mod = 1e9 + 7;

int main() {
  string K; cin >> K;
  int D; cin >> D;
  int N = K.size();
  vector<vector<vector<ll>>> dp(N, vector<vector<ll>>(D, vector<ll>(2, 0)));
  dp[0][0][0] = 1;
  for (int i = 1; i <= N; ++i) {
    int currD = K[i - 1];
    for (int j = 0; j < D; ++j) {
      dp[i][j][0] = (dp[i][j][0] + dp[i - 1][(j - currD + D) % D][0]) % mod;
      for (int d = 0; d <= 9; ++d) {
        dp[i][j][1] = (dp[i][j][1] + dp[i - 1][(j - d + D) % D][k]) % mod;
        if (d < currD) {
          dp[i][j][1] = (dp[i][j][1] + dp[i - 1][(j - d + D) % D][0]) % mod;
        }
      }
    }
  }

  cout << (dp[N + 1][0][0] + dp[N + 1][0][1]) % mod << endl;
  return 0;
}
