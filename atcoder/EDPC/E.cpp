#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, W; cin >> N >> W;
  vector<int> weight(N), value(N);
  for (int i = 0; i < N; ++i) cin >> weight[i] >> value[i];

  vector<int> dp(1e5 + 1, W + 1);
  dp[0] = 0;
  for (int i = 0; i < N; ++i) {
    auto nextDp = dp;
    for (int v = 0; v < dp.size() - value[i]; ++v) {
      int nv = v + value[i];
      int nw = dp[v] + weight[i];
      nextDp[nv] = min(nextDp[nv], nw);
    }
    dp = nextDp;
  }
  for (int i = 1e5; i >= 0; --i) {
    if (dp[i] != W + 1) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}
