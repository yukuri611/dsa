#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll mod = 1e9 + 7;

int main() {
  int N, K; cin >> N >> K;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }

  vector<ll> dp(K + 1,0); //dp[j] = 飴インデックスjの時の通り数
  dp[K] = 1;
  vector<ll> sumDp(K + 2,1); //sumDp[i] = dp[i] からdp[K]までの和
  sumDp[K + 1] = 0;
  
  for (int i = N - 1; i >= 0; --i) {
    vector<ll> nextDp(K + 1,1);
    vector<ll> nextSumDp(K + 2, 1);
    for (int j = K-1; j >= 0; --j) {
      nextDp[j] = sumDp[j] - sumDp[min(j + A[i] + 1, K + 1)];
      nextSumDp[j] = (nextSumDp[j + 1] + nextDp[j]) % mod;
    }
    dp = nextDp;
    sumDp = nextSumDp;
  }

  cout << dp[0] << endl;
  return 0;
}
