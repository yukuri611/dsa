#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, K; cin >> N >> K;
  vector<int> decided(N + 1,0);
  for (int _ = 0; _ < K; ++_) {
    int a, b; cin >> a >> b;
    decided[a] = b;
  }

  vector<vector<int>> dp(4, vector<int>(4,0));
  if (decided[1] && decided[2]) dp[decided[2]][decided[1]] = 1;
  else if (decided[1]) for (int i = 1; i < 4; ++i) dp[i][decided[1]] = 1;
  else if (decided[2]) for (int i = 1; i < 4; ++i) dp[decided[2]][i] = 1;
  else for (int i = 1; i < 4; ++i) for (int j = 1; j < 4; ++j) dp[i][j] = 1;

  for (int day = 3; day <= N; ++day) {
    vector<vector<int>> nextDp(4,vector<int>(4,0));
    if (decided[day]) {
      int pasta = decided[day];
      for (int i = 1; i < 4; ++i) {
        int sum = 0;
        for (int j = 1; j < 4; ++j) sum += dp[i][j] % 10000;
        if (i == pasta) sum -= dp[i][i] % 10000;
        nextDp[pasta][i] = sum;
      }
    }
    else {
      for (int i = 1; i < 4; ++i) {
        for (int j = 1; j < 4; ++j) {
          int sum_j = 0;
          for (int k = 1; k < 4; ++k) sum_j += dp[j][k] % 10000;
          if (i == j) sum_j -= dp[j][j];
          nextDp[i][j] = sum_j;
        }
      }
    }
    dp = nextDp;
  }

  int sum = 0;
  for (int i = 1; i < 4; ++i) {
    for (int j = 1; j < 4; ++j) {
      sum += dp[i][j];
      sum %= 10000;
    }
  }
  cout << sum << endl;
  return 0;
}
