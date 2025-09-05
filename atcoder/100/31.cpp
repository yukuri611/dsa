#include <bits/stdc++.h>

using namespace std;
int dh[6] = {-1,0,1,1,0,-1};
int dw[2][6] = {
  {0,1,0,-1,-1,-1},
  {1,1,1,0,-1,0}
};

void dfs(int h, int w, vector<vector<int>> &G, vector<vector<bool>> &seen, int &res) {
  for (int i = 0; i < 6; ++i) {
    int nh, nw; nh = h + dh[i];
    if (h % 2 == 0) nw = w + dw[0][i];
    else nw = w + dw[1][i];

    if (nh < 0 || nh >= G.size() || nw < 0 || nw >= G[0].size()) continue;
    if (G[nh][nw]) {
      res++;
      continue;
    }
    if (seen[nh][nw]) continue;
    seen[nh][nw] = true;
    if (G[nh][nw]) res++;
    else dfs(nh, nw, G, seen, res);
  }
}

int main() {
  int W, H; cin >> W >> H;
  vector<vector<int>> G(H + 2, vector<int>(W + 2)); //外周をつけている
  for (int h = 1; h <= H; ++h) {
    for (int w = 1; w <= W; ++w) {
      cin >> G[h][w];
    }
  }

  int res = 0;
  vector<vector<bool>> seen(H + 2, vector<bool>(W + 2));
  dfs(0,0,G,seen,res);
  cout << res << endl;
  return 0;
}
