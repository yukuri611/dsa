#include <bits/stdc++.h>

using namespace std;


int main() {
  int N, K; cin >> N >> K;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) cin >> A[i];

  vector<int> dp(N, INT_MAX);
  dp[0] = 0;
  for (int i = 0; i < N; ++i) {
    for (int k = 1; k <= K; ++k) {
      if (i + k >= N) break;
      dp[i + k] = min(dp[i + k], dp[i] + abs(A[i] - A[i + k]));
    }
  }

  cout << dp[N-1] << endl;
  return 0;
}
