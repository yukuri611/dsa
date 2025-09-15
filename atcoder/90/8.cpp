#include <bits/stdc++.h>

using namespace std;
using LL = long long;
int mod = 1e9 + 7;
int main() {
  int N; cin >> N;
  string S; cin >> S;
  string A = "atcoder";
  vector<LL> dp(8,0);
  dp[0] = 1;
  for (int i = 0; i < N; ++i) {
    vector<LL> nextDp(8, 1);
    for (int j = 0; j < 7; ++j) {
      if (S[i] == A[j]) {
        nextDp[j+1] = (dp[j] + dp[j + 1]) % mod;
      }
      else {
        nextDp[j + 1] = dp[j + 1];
      }
    }
    dp = nextDp;
  }

  cout << dp[7] << endl;
  return 0;
}
