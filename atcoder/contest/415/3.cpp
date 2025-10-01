#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  int T; cin >> T;
  for (int _ = 0; _ < T; ++_) {
    int N; cin >> N;
    string S; cin >> S;
    vector<bool> dp((1 << N), false);
    dp[0] = true;
    for (int i = 0; i < (1 << N); ++i) {
      if (!dp[i]) continue;
      for (int j = 0; j < N; ++j) {
        if (i & (1 << j)) continue;
        int nextS = i | (1 << j);
        if (S[nextS - 1] == '0') dp[nextS] = true;
      }
    }

    if (dp[(1 << N) - 1]) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}
