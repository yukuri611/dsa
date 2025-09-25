#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll solve(const string &S) {
  const int L = S.size();

  vector<vector<vector<ll>>> dp(L + 1, vector<vector<ll>>(2, vector<ll>(2,0))); //dp[i][j][k] = 上からi桁目まで決定済み、jは未満フラグ、kは4||9を含むか否か
  dp[0][0][0] = 1;
  for (int i = 0; i < L; ++i) {
    const int D = S[i] - '0';
    for (int j = 0; j < 2; ++j) {
      for (int k = 0; k < 2; ++k) {
        for (int d = 0; d <= (j ? 9: D); ++d) {
          dp[i + 1][j || d < D][k || d == 4 || d == 9] += dp[i][j][k];
        }
      }
    }
  }

  return dp[L][0][1] + dp[L][1][1];
}
int main() {
  ll A, B; cin >> A >> B;
  ll res = solve(to_string(B)) - solve(to_string(A - 1));
  cout << res << endl;
  return 0;
}
