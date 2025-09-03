#include <vector>
#include <iostream>
#include <climits>

using namespace std;

int main() {
  int n, m; cin >> n >> m;
  vector<int> coin(m);
  for (int i = 0; i < m; ++i) cin >> coin[i];

  vector<int> dp(n+1,INT_MAX);
  dp[0] = 0;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n + 1; ++j) {
      if (j - coin[i] < 0) continue;
      dp[j] = min(dp[j], dp[j-coin[i]] + 1);
    }
  }

  cout << dp[n] << endl;
  return 0;
}
