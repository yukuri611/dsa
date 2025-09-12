#include <bits/stdc++.h>

using namespace std;
using LL = long long;

int main() {
  int N; cin >> N;
  vector<vector<LL>> D(N, vector<LL>(N));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> D[i][j];
    }
  }

  //存在するかどうかの判定
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int k = 0; k < N; ++k) {
        if (D[i][k] + D[k][j] < D[i][j]) {
          cout << -1 << endl;
          return 0;
        }
      }
    }
  }

  //どれだけの道を削減することができるか
  vector<vector<bool>> canBreak(N, vector<bool>(N, false));

  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      for (int k = 0; k < N; ++k) {
        if (i == k || j == k) continue;
        if (D[i][k] + D[k][j] == D[i][j]) {
          canBreak[i][j] = true;//橋を破壊
          break;
        }
      }
    }
  }

  LL sum = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      if (!canBreak[i][j]) sum += D[i][j];
    }
  }
  cout << sum << endl;
  return 0;
}
