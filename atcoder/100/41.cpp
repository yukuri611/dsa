#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int D, N; cin >> D >> N;
  vector<int> T(D + 1,0);
  for (int i = 1; i <= D; ++i) cin >> T[i];
  vector<int> A(N + 1), B(N + 1), C(N + 1);
  for (int i = 1; i <= N; ++i) cin >> A[i] >> B[i] >> C[i];

  vector<int> dp(N + 1, 0);
  for (int i = 2; i <= D; ++i) {
    vector<int> nextDp(N + 1, 0);
    for (int j = 1; j <= N; ++j) {
      if (T[i] < A[j] || T[i] > B[j]) continue;
      for (int k = 1; k <= N; ++k) {
        if (T[i - 1] < A[k] || T[i - 1] > B[k]) continue;
        nextDp[j] = max(nextDp[j], dp[k] + abs(C[k] - C[j]));
      }
    }
    dp = nextDp;
  }
  auto res = max_element(dp.begin(), dp.end());
  cout << *res << endl;
  return 0;
}
