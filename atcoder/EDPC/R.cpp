#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll mod = 1e9 + 7;

int main() {
  string K; cin >> K;
  int D; cin >> D;
  int N = K.size();
  vector<vector<vector<ll>>> dp(N + 1, vector<vector<ll>>(2, vector<ll>(D, 0)));
  dp[0][0][0] = 1;
  for (int i = 0; i < N; ++i) {
    int currD = K[i] - '0';
    for (int j = 0; j < 2; ++j) {
      for (int k = 0; k < D; ++k) {
        for (int d = 0; d <= (j ? 9 : currD); ++d) {
          dp[i + 1][j || d < currD][(k + d) % D] = (dp[i + 1][j || d < currD][(k + d) % D] + dp[i][j][k]) % mod;
        }
      }
    }
  }

  cout << (dp[N][0][0] + dp[N][1][0] - 1 + mod) % mod << endl;
  return 0;
}
