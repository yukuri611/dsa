#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, K; cin >> N >> K;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) cin >> A[i];

  vector<vector<int>> dp(K + 1, vector<int>(2));
  for (int i = 0; i <= K; ++i) {
    dp[i][0] = 1;
    dp[i][1] = 0;
  }

  for (int i = 0; i <= K; ++i) {
    for (int j = 0; j < N; ++j) {
      if (i + A[j] <= K) {
        if (dp[i][1] == 0) {
          dp[i + A[j]][0] = 0;
        }
        if (dp[i][0] == 1) {
          dp[i + A[j]][1] = 1;
        }
      }
    }
  }

  if (dp[K][0] == 0) {
    cout << "First" << endl;
  }
  else {
    cout << "Second" << endl;
  }
  return 0;

}
