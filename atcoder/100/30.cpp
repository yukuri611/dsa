#include <vector>
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

vector<int> dh = {0,1,0,-1};
vector<int> dw = {1,0,-1,0};

int main() {
  int H, W, N; cin >> H >> W >> N;
  vector<string> G(H);
  for (int h = 0; h < H; ++h) cin >> G[h];

  vector<pair<int, int>> factory(N + 1);
  for (int h = 0; h < H; ++h) {
    for (int w = 0; w < W; ++w) {
      if (G[h][w] == 'S') factory[0] = {h, w};
      else if (G[h][w] != '.' && G[h][w] != 'X') factory[G[h][w] - '0'] = {h,w};
    }
  }

  int res = 0;
  for (int i = 0; i < N; ++i) {
    vector<vector<int>> dist(H, vector<int>(W,-1));
    queue<pair<int, int>> q;
    q.push({factory[i].first, factory[i].second});
    dist[factory[i].first][factory[i].second] = 0;
    while(!q.empty()) {
      pair<int, int> p = q.front();
      q.pop();
      int h, w; h = p.first; w = p.second;
      for(int i = 0; i < 4; ++i) {
        int nh, nw; nh = h + dh[i]; nw = w + dw[i];
        if (nh < 0 || nh >= H || nw < 0 || nw >= W) continue;
        if (dist[nh][nw] != -1) continue;
        if (G[nh][nw] == 'X') continue;
        dist[nh][nw] = dist[h][w] + 1;
        q.push({nh, nw});
      }
    }
    res += dist[factory[i + 1].first][factory[i + 1].second];
  }

  cout << res << endl;
  return 0;
}
