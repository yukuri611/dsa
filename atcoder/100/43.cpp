#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int N; cin >> N;
  vector<string> S(5);
  for (int i = 0; i < 5; ++i) cin >> S[i];

  vector<int> dp(3, 0); // R, B, W
  for (int i = 0; i < N; ++i) {
    vector<int> nextDp(3,0);
    int r, b, w; r = b = w = 0;
    for (int j = 0; j < 5; ++j) {
      if (S[j][i] == 'R') r++;
      else if (S[j][i] == 'B') b++;
      else if (S[j][i] == 'W') w++;
    }
    nextDp[0] = min(dp[1], dp[2]) + (5 - r);
    nextDp[1] = min(dp[2], dp[0]) + (5 - b);
    nextDp[2] = min(dp[0], dp[1]) + (5 - w);
    dp = nextDp;
  }

  auto res = min_element(dp.begin(), dp.end());
  cout << *res << endl;
  return 0;
}
