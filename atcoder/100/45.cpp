#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> res_list;
  while(true) {
    int N, M; cin >> N >> M;
    if (N == 0 && M == 0) break;
    vector<int> C(M);
    for (int i = 0; i < M; ++i) cin >> C[i];
    vector<int> X(N);
    for (int i = 0; i < N; ++i) cin >> X[i];


    vector<int> dp(256,INT_MAX);
    for (int x: X) {
      vector<int> nextDp(256, INT_MAX);
      for (int prev = 0; prev < 256; ++prev){
        for (int i = 0; i < M; ++i) {
          int y = prev + C[i];
          y = min(y, 255);
          y = max(y, 0);
          int diff = (y - x) * (y - x);
          nextDp[y] = min(nextDp[y], dp[prev] + diff);
        }
      }
    }
    int res = *max_element(dp.begin(), dp.end());
    res_list.push_back(res);
  }
  for (int res: res_list) cout << res << endl;
  return 0;
}
