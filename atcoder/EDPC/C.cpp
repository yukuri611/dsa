#include <bits/stdc++.h>

using namespace std;

int main() {
  int N; cin >> N;
  vector<int> A(N), B(N), C(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i] >> B[i] >> C[i];
  }

  vector<int> dp(3, 0);
  for (int i = 0; i < N; ++i) {
    vector<int> nextDp(3);
    nextDp[0] = max(dp[1] + A[i], dp[2] + A[i]);
    nextDp[1] = max(dp[0] + B[i], dp[2] + B[i]);
    nextDp[2] = max(dp[0] + C[i], dp[1] + C[i]);
    dp = nextDp;
  }
  cout << *(max_element(dp.begin(), dp.end())) << endl;
  return 0;
}
