#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  int T; cin >> T;
  vector<int> res_list(T);
  for (int l = 0; l < T; ++l) {
    int H, W; cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; ++i) cin >> S[i];
    vector<vector<int>> Count(H, vector<int>(W,0));
    for (int r = 0; r < H-1; ++r) {
      for (int c = 0; c < W-1; ++c) {
        if (S[r][c] == '#' && S[r][c + 1] == '#' && S[r + 1][c] == '#' && S[r + 1][c + 1] == '#') {
          Count[r][c]++; Count[r][c+1]++; Count[r + 1][c]++; Count[r + 1][c + 1]++;
        }
      }
    }

    int res = 0;
    while (true) {
      int maximum = 0;
      int maxR = 0; int maxC = 0;
      for (int r = 0; r < H; ++r) {
        for (int c = 0; c < W; ++c) {
          if (maximum < Count[r][c]) {
            maxR = r; maxC = c; maximum = Count[r][c];
          }
        }
      }
      if (maximum == 0) break;
      else {
        res++;
        if (maxR > 0 && maxC > 0) {
          int r = maxR - 1; int c = maxC - 1;
          bool valid = true;
          for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
              if (Count[r + i][c + j] == 0) valid = false;
            }
          }
          if (valid) {
            Count[r][c]--;
            Count[r][c + 1]--;
            Count[r + 1][c]--;
            Count[r + 1][c + 1]--;
          }
        }
        if (maxR > 0) {
          int r = maxR - 1; int c = maxC;
          bool valid = true;
          for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
              if (Count[r + i][c + j] == 0) valid = false;
            }
          }
          if (valid) {
            Count[r][c]--;
            Count[r][c + 1]--;
            Count[r + 1][c]--;
            Count[r + 1][c + 1]--;
          }
        }
        if (maxR < H -1) {
          int r = maxR; int c = maxC - 1;
          bool valid = true;
          for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
              if (Count[r + i][c + j] == 0) valid = false;
            }
          }
          if (valid) {
            Count[r][c]--;
            Count[r][c + 1]--;
            Count[r + 1][c]--;
            Count[r + 1][c + 1]--;
          }
        }
        if (maxC < W - 1) {
          int r = maxR; int c = maxC;
          bool valid = true;
          for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
              if (Count[r + i][c + j] == 0) valid = false;
            }
          }
          if (valid) {
            Count[r][c]--;
            Count[r][c + 1]--;
            Count[r + 1][c]--;
            Count[r + 1][c + 1]--;
          }
        }
      }
    }
    res_list[l] = res;
  }
  for (int res: res_list) cout << res << endl;
  return 0;
}
