#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
vector<int> dh = {1,0,-1,0};
vector<int> dw = {0,1,0,-1};

int main() {
  int H, W; cin >> H >> W;
  vector<string> g(H);
  int c = 0;
  for (int h = 0; h < H; ++h) {
    cin >> g[h];
    c += count(g[h].begin(), g[h].end(), '#');
  }

  queue<pair<int, int>> q;
  vector<vector<int>> dist(H, vector<int>(W,-1));
  q.push({0,0});
  dist[0][0] = 1;
  while(!q.empty()) {
    pair<int, int> p = q.front();
    q.pop();
    int h, w; h = p.first; w = p.second;
    for (int i = 0; i < 4; ++i) {
      int nh, nw; nh = h + dh[i]; nw = w + dw[i];
      if (nh < 0 || nh >= H || nw < 0 || nw >= W) continue;
      if (g[nh][nw] == '#') continue;
      if (dist[nh][nw] != -1) continue; 
      q.push({nh, nw});
      dist[nh][nw] = dist[h][w] + 1;
    }
  }

  if (dist[H-1][W-1] == -1) {
    cout << -1 << endl;
  }
  else {
    cout << H * W - c - dist[H-1][W-1] << endl;
  }
  return 0;


}
