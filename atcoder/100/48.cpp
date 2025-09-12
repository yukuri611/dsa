#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> res_list;
  while (true) {
    int n; cin >> n;
    if (n == 0) break;
    vector<int> W(n);
    for (int i = 0; i < n; ++i) cin >> W[i];

    vector<vector<int>> dp(n, vector<int>(n,INT_MAX));
    for (int i = 0; i < n; ++i) dp[i][i] = 1;
    for (int l = 2; l <= n; ++l) {
      for (int i = 0; i < n - l + 1; ++i) {
        int j = i + l - 1;
        if (l == 2) {
          if (abs(W[i] - W[j]) <= 1) dp[i][j] = 0;
          else  dp[i][j] = 2;
          continue;
        }
        if (abs(W[i] - W[j]) <= 1 && dp[i + 1][j - 1] == 0) {
          dp[i][j] = 0;
          continue;
        }
        for (int k = i; k < j; ++k) {
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
        } 
      }
    }

    res_list.push_back(n - dp[0][n-1]);
  }
  for (int res: res_list) cout << res << endl;
  return 0;
}
