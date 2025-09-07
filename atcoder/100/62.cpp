#include <bits/stdc++.h>

using namespace std;

int main() {
  int H, W; cin >> H >> W;
  vector<vector<int>> C(10, vector<int>(10));
  for (int i = 0; i <= 9; ++i) {
    for (int j = 0; j <= 9; ++j) {
      cin >> C[i][j];
    }
  }

  for (int k = 0; k < 10; ++k) {
    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < 10; ++j) {
        C[i][j] = min(C[i][j], C[i][k] + C[k][j]);
      }
    }
  }

  int res = 0;
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      int a; cin >> a;
      if (a == -1) continue;
      res += C[a][1];
    }
  }

  cout << res << endl;
  return 0;
}
