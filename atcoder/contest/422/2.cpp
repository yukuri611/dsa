#include <bits/stdc++.h>

using namespace std;

int dh[4] = {0,1,0,-1};
int dw[4] = {1,0,-1,0};

int main() {
  int H, W; cin >> H >> W;
  vector<string> S(H);
  for (int i = 0; i < H; ++i) {
    cin >> S[i];
  }

  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      if (S[i][j] == '.') continue;
      int count = 0;
      for (int k = 0; k < 4; ++k) {
        int h, w; h = i + dh[k]; w = j + dw[k];
        if (h < 0 || h >= H || w < 0 || w >= W) continue;
        if (S[h][w] == '#') count++;
      }
      if (count == 0 || count == 1 || count == 3){
        cout << "No" << endl;
        return 0;
      }
    }
  }

  cout << "Yes" << endl;
  return 0;
}
