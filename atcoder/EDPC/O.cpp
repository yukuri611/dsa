#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll mod = 1e9 + 7;

int main() {
  int N; cin >> N;
  vector<vector<int>> A(N, vector<int>(N));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> A[i][j];
    }
  }

  vector<ll> dp((1 << N), 0);
  dp[0] = 1;
  for (int i = 0; i < N; ++i) {
    for (int s = 0; s < (1 << N); ++s) {
      if (__builtin_popcount(s) != i) continue;

      for (int j = 0; j < N; ++j) {
        if ((s >> j) & 1) continue;
        if (A[i][j] == 0) continue;
        int nextS = s | (1 << j);
        dp[nextS] = (dp[nextS] + dp[s]) % mod; 
      } 
    }
  }

  cout << dp[(1 << N) - 1] << endl;
  return 0;
  
}
