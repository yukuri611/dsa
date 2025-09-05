#include <bits/stdc++.h>

using namespace std;
using LL = long long;

int main() {
  int N; cin >> N;
  vector<int> nums(N - 1);
  for (int i = 0; i < N-1; ++i) cin >> nums[i];
  int ans; cin >> ans;

  vector<LL> dp(21, 0);
  dp[nums[0]] = 1;
  for (int i = 1; i < N - 1; ++i) {
    vector<LL> nextDp(21,0);
    int n = nums[i];
    for (int j = 0; j < 21; ++j) {
      if (j - n >= 0) nextDp[j - n] += dp[j];
      if (j + n < 21) nextDp[j + n] += dp[j];
    }
    dp = nextDp;
  }

  cout << dp[ans] << endl;
  return 0;
}
