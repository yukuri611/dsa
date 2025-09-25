#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll mod = 1e9 + 7;

ll solve(ll D, string N) {
  int L = N.size();
  vector<vector<vector<ll>>> dp(L + 1, vector<vector<ll>>(2, vector<ll>(D, 0)));
  dp[0][0][0] = 1;
  for (int i = 0; i < L; ++i) {
    int N_i = N[i] - '0';
    for (int j = 0; j < 2; ++j) {
      for (int k = 0; k < D; ++k) {
        for (int d = 0; d <= (j ? 9: N_i); ++d){
          dp[i + 1][j || d < N_i][(k + d) % D] = (dp[i + 1][j || d < N_i][(k + d) % D] + dp[i][j][k]) % mod;
        }
      }
    }
  }
  ll ans = (dp[L][0][0] + dp[L][1][0]) % mod;
  return (ans - 1) % mod;
}

int main() {
  ll D; cin >> D;
  string N; cin >> N;
  ll res = solve(D, N);
  cout << res << endl;
  return 0;
}
