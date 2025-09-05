#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, w_max; cin >> N >> w_max;
  vector<int> V(N), W(N);
  for (int i = 0; i < N; ++i) cin >> V[i] >> W[i];

  vector<int> dp(w_max + 1, 0);
  for (int i = 0; i < N; ++i){
    for (int w = W[i]; w <= w_max; ++w) {
      dp[w] = max(dp[w], dp[w - W[i]] + V[i]);
    }
  }

  cout << *max_element(dp.begin(), dp.end()) << endl;
  return 0;
}
