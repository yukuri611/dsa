#include <bits/stdc++.h>

using namespace std;

int main() {
  int q; cin >> q;
  vector<int> res_list(q);
  for (int k = 0; k < q; ++k){
    string X, Y; cin >> X >> Y;
    int res = 0;
    vector<int> dp(Y.size() + 1, 0); //dp[i][j] = X[i-1]Y[j-1]までの最長共通部分列
    for (int i = 0; i < X.length(); ++i) {
      int prev = dp[0];
      for (int j = 0; j < Y.length(); ++j) {
        int temp = dp[j + 1];
        dp[j + 1] = max(dp[j + 1], dp[j]);
        if (X[i] == Y[j]) dp[j + 1] = max(dp[j + 1], prev + 1);
        prev = temp;
      }
    }
    res_list[k] = dp[Y.size()];
  }
  for (int res: res_list) cout << res << endl;
  return 0;
}
