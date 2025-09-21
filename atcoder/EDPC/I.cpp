#include <bits/stdc++.h>

using namespace std;

int main() {
  int N; cin >> N;
  vector<double> P(N);
  for (int i = 0; i < N; ++i) {
    cin >> P[i];
  }

  vector<double> dp(N + 1, 0);
  dp[0] = 1;
  for (int i = 0; i < N; ++i) {
    double prev = dp[0];
    dp[0] *= (1 - P[i]);
    for (int j = 1; j <= i + 1; ++j) {
      double temp = dp[j];
      dp[j] = P[i] * prev + (1 - P[i]) * dp[j];
      prev = temp;
    }
  }

  double res = 0;
  for (int i = N/2 + 1; i <= N; ++i) {
    res += dp[i];
  }
  cout << fixed << setprecision(9) << res << endl;
  return 0;
}
