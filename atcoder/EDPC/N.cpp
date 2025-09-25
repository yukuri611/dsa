#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  int N; cin >> N;
  vector<ll> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }

  vector<ll> sum(N + 1,0); //sum[i] = インデックス0からi-1までの和
  for (int i = 1; i <= N; ++i){
    sum[i] += sum[i - 1] + A[i-1];
  }

  vector<vector<ll>> dp(N, vector<ll>(N + 1, LLONG_MAX));
  for (int i = 0; i < N; ++i) dp[i][i] = 0;

  for (int l = 2; l <= N; ++l) {
    for (int i = 0; i < N - l + 1; ++i) {
      int j = i + l - 1;
      for (int k = i; k < j; ++k) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum[j + 1] - sum[i]);
      }
    }
  }

  cout << dp[0][N-1] << endl;
  return 0;
}
