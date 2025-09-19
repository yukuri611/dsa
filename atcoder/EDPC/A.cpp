#include <bits/stdc++.h>

using namespace std;

int main() {
  int N; cin >> N;
  vector<int>H(N);
  for (int i = 0; i < N; ++i) cin >> H[i];
  int dp1 = 0; int dp2 = abs(H[1] - H[0]);
  for (int i = 2; i < N; ++i) {
    int dp = min(dp1 + abs(H[i - 2] - H[i]), dp2 + abs(H[i - 1] - H[i]));
    dp1 = dp2;
    dp2 = dp;
  }
  cout << dp2 << endl;
  return 0;
}
