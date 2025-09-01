#include <bits/stdc++.h>

using namespace std;

vector<vector<int>>dh = {
  {-1,0,1,1,0,-1},
  {-1,0,1,1,0,-1}
};
vector<vector<int>>dw = {
  {0,1,0,-1,-1,-1},
  {1,1,1,0,-1,0},
};


int main() {
  int W, H; cin >> W >> H;
  vector<vector<int>> grid(H+2, vector<int>(W+2, 0));
  for (int h = 1; h <= H; ++h) for (int w = 1; w <= W; ++w) cin >> grid[h][w];

  vector<vector<bool>>visited(H+2, vector<bool>(W+2,false));
  queue<pair<int, int>> q;
  q.push({0,0});
  visited[0][0] = true;
  while (!q.empty()) {
    pair<int, int> p = q.front();
    q.pop();
    int h, w; h = p.first; w = p.second;
    for(int i = 0; i < 6; ++i) {
      int nh, nw; nh = h + dh[h % 2][i]; nw = w + dw[h % 2][i];
      if(nh < 0 || nh >= H + 2 || nw < 0 || nw >= W + 2) continue;
      if (visited[nh][nw]) continue;
      if (grid[nh][nw] == 0) {
        visited[nh][nw] = true;
        q.push({nh,nw});
      }
    }
  }

  for (int h = 0; h < H+2; ++h) for (int w = 0; w < W + 2; ++w){
    if (!visited[h][w]) grid[h][w] = 1;
  };


  int res = 0;
  for (int h = 1; h < H+1; ++h) for (int w = 1; w < W+1; ++w) {
    if (grid[h][w] == 1) {
      for (int i = 0; i < 6; ++i) {
        int nh, nw; nh = h + dh[h % 2][i]; nw = w + dw[h % 2][i];
        if (grid[nh][nw] == 0) res++;
      }
    }
  }
  cout << res << endl;
  return 0;
}
