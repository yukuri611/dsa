#include <bits/stdc++.h>

using namespace std;

int main() {
  int q; cin >> q;
  vector<int> res_list(q);
  for (int q_i = 0; q_i < q; ++q_i) {
    string X, Y; cin >> X >> Y;

    vector<int> dp(Y.length(), 0);
    for (int i = 0; i < X.length(); ++i) {
      int prev = 0;
      for (int j = 0; j < Y.length(); ++j) {
        int temp = dp[j];
        if (X[i] == Y[j]) dp[j] = prev + 1;
        else {
          if (j > 0) dp[j] = max(dp[j-1], temp);
        }
        prev = temp;
      }
    }

    res_list[q_i] = dp[Y.length()-1];
  }
  for (int res: res_list) cout << res << endl;
  return 0;
}
