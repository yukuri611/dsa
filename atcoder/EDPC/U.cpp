#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<vector<ll>> A;


int main() {
  int N; cin >> N;
  A.resize(N, vector<ll>(N));
  for(int i = 0; i < N; ++i) for(int j = 0; j < N; ++j) cin >> A[i][j];

  

  vector<ll> group_score(1 << N, 0);
  for (int i = 0; i < N; ++i) {
      for (int j = i + 1; j < N; ++j) {
          for (int mask = 0; mask < (1 << N); ++mask) {
              if (((mask >> i) & 1) && ((mask >> j) & 1)) {
                  group_score[mask] += A[i][j];
              }
          }
      }
  }

  vector<ll> dp((1 << N), 0);
  for (int s = 1; s < (1 << N); ++s) {
    for (int t = s; t > 0; t = (t - 1) & s ) {
      int u = s ^ t;
      dp[s] = max(dp[s], group_score[t] + dp[u]);
    }
  }

  cout << dp[(1 << N) - 1] << endl;
  return 0;
}
