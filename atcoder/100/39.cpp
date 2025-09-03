#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N; cin >> N;
  vector<int> nums(N-1);
  int sum;
  for (int i = 0; i < N-1; ++i) cin >> nums[i];
  cin >> sum;

  vector<long long> dp(21,0);
  dp[0] = 1;
  for (int i = 0; i < nums.size(); ++i) {
    vector<long long> nextDp(21,0);
    for (int j = 0; j < 21; ++j) {
      if (j + nums[i] < 21) nextDp[j + nums[i]] += dp[j];
      if (j - nums[i] > -1) nextDp[j - nums[i]] += dp[j];
    }
    dp = nextDp;
  }

  cout << dp[sum] << endl;
  return 0;

}
