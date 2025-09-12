#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, M, Q; cin >> N >> M >> Q;
  vector<vector<int>> imos(N, vector<int>(N,0));
  for (int i = 0; i < M; ++i) {
    int l, r; cin >> l >> r;
    l--; r--;
    imos[l][r] += 1;
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N-1; ++j) {
      imos[i][j + 1] += imos[i][j];
    }
  }
  for (int i = N - 2; i >= 0; --i) {
    for (int j = 0; j < N; ++j) {
      imos[i][j] += imos[i + 1][j];
    }
  }
  vector<int> res_list(Q);
  for (int i = 0; i < Q; ++i) {
    int p, q; cin >> p >> q;
    p--; q--;
    res_list[i] = imos[p][q];
  }
  for (int res : res_list) cout << res << endl;
  return 0;
}
