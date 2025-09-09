#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, M, Q; cin >> N >> M >> Q;
  vector<vector<int>> cnt(N + 1, vector<int>(N + 1, 0)); //cnt[i][j] = 左端が iで右端がj以下の列車の個数

  for (int i = 0; i < M; ++i) {
    int l, r; cin >> l >> r;
    cnt[l][r] += 1;
  }
  for (int l = 1; l < N + 1; ++l) {
    for (int r = l; r < N + 1; ++r) {
      cnt[l][r] += cnt[l][r-1];
    }
  }

  for (int i = 0; i < Q; ++i) {
    int p, q; cin >> p >> q;
    int res = 0; 
    for (int l = p; l < q + 1; ++l) {
      res += cnt[l][q];
    }
    cout << res << endl;
  }
  
  return 0;
}
