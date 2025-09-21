#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll mod = 1e9 + 7;

int main() {
  int H, W; cin >> H >> W;
  vector<string> A(H);
  for (int i = 0; i < H; ++i) {
    string S; cin >> S;
    A[i] = S;
  }

  vector<ll> dp(W + 1,0);
  dp[1] = 1;
  for (int i = 1; i <= H; ++i) {
    for (int j = 1; j <= W; ++j) {
      if (A[i-1][j-1] == '#') {
        dp[j] = 0;
        continue;
      }
      if (j - 2 >= 0 && A[i-1][j-2] == '.') {
        dp[j] = (dp[j] + dp[j-1]) % mod;
      }
    }
  }

  cout << dp[W] << endl;
  return 0;

}
