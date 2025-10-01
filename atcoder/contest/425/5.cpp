#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<vector<ll>> bino(5001,vector<ll>(5001, 0));



int main() {
  int T, M; cin >> T >> M;
  
  bino[0][0] = 1;
  for (int n = 1; n < 5001; ++n) {
    bino[n][0] = 1;
    for (int k = 1; k <= n; ++k) {
      bino[n][k] = (bino[n - 1][k - 1] + bino[n - 1][k]) % M;
    }
  }

  for (int _ = 0; _ < T; ++_) {
    int N; cin >> N;
    vector<int> C(N);
    for (int i = 0; i < N; ++i) cin >> C[i];
    ll res = 1;
    ll sum = 0;
    for (int i = 0; i < N; ++i) {
      sum += C[i];
      res = (res * bino[sum][C[i]]) % M;
    }

    cout << res << endl;
  }

  return 0;
}
