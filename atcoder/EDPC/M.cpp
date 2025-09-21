#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll mod = 1e9 + 7;

int main() {
  int N, K; cin >> N >> K;
  vector<ll> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }

  vector<ll> dp(K + 2,1); //dp[j] = 現在見ている飴がj番目の飴（1インデックスとする）
  dp[0] = 0;
  for (int i = 0; i < N; ++i) {
    vector<ll> nextDp(K + 2,0);
    for (int j = 1; j < K + 2; ++j) {
      nextDp[j] = (dp[j] - dp[max(j - A[i] - 1, 0LL)] + mod) % mod;
    }
    for (int j = 1; j < K + 2; ++j) {
      nextDp[j] = (nextDp[j] + nextDp[j - 1]) % mod;
    }
    dp = nextDp;
  }
  cout << (dp[K + 1] - dp[K] + mod) % mod<< endl;
  return 0;
}
