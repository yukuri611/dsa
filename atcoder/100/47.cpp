#include <bits/stdc++.h>

using namespace std;
using LL = long long;

int main() {
  int N; cin >> N;
  vector<int> A(2 * N);
  for (int i = 0; i < N; ++i) cin >> A[i];
  for (int i = 0; i < N; ++i) A[N + i] = A[i];
  vector<vector<LL>> dp(2 * N, vector<LL>(2 * N,0)); // dp[i][j] = i からjまで残っているときのJOIの最大得点

  for (int l = 1; l <= N; ++l) {
    for (int i = 0; i < 2 * N - l + 1; ++i){
      int j = i + l - 1;
      if ((N-l) % 2 == 0) {
        //JOI
        if (i == j) dp[i][j] = A[i];
        else dp[i][j] = max(dp[i+1][j] + A[i], dp[i][j-1] + A[j]);
      }
      else {
        dp[i][j] = (A[i] > A[j]) ? dp[i + 1][j] : dp[i][j - 1];
      }
    }
  }

  LL maxScore = 0;
  for (int i = 0 ; i < N; ++i) {
    maxScore = max(maxScore, dp[i + 1][i + N - 1] + A[i]); //最初の一回は自由にとれる
  }
  cout << maxScore << endl;
  return 0;
}
