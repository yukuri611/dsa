#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
  int N, M; cin >> N >> M;
  vector<int> D(N + 1);
  for (int i = 1; i <= N; ++i) cin >> D[i];
  vector<int> C(M + 1);
  for (int i = 1; i <= M; ++i) cin >> C[i];

  vector<int> dp(N + 1, INT_MAX);
  dp[0] = 0;
  for (int day = 1; day <= M; ++day) {
    for (int i = N; i >= 1; --i) {
      if (dp[i - 1] == INT_MAX) continue;
      dp[i] = min(dp[i], dp[i-1] + C[day] * D[i]);
    }
  }

  cout << dp[N] << endl;
  return 0;
}
