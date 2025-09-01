#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> dh = {1,-1,0,0};
vector<int> dw = {0,0,1,-1};

int main() {
  vector<int> res_list;
  while (true) {
    int W, H; cin >> W >> H;
    if (W == 0 && H == 0) break;
    vector<vector<vector<int>>> g(H, vector<vector<int>>(W, vector<int>(2))); //right, down
    for (int h = 0; h < 2 * H - 1; ++h) {
      if (h % 2 == 0) {
        //right
        for (int w = 0; w < W - 1; ++w) {
          cin >> g[h / 2][w][0];
        }
      }
      else {
        for (int w = 0; w < W; ++w) {
          cin >> g[h / 2][w][1];
        }
      }
    }

    queue<pair<int, int>> q;
    vector<vector<int>> dist(H, vector<int>(W, -1));
    q.push({0,0});
    dist[0][0] = 1;
    while(!q.empty()) {
      pair<int, int> p = q.front();
      q.pop();
      int h, w; h = p.first; w = p.second;
      for (int i = 0; i < 4; ++i) {
        int nh, nw; nh = h + dh[i]; nw = w + dw[i];
        if (nh < 0 || nh >= H || nw < 0 || nw >= W) continue;
        if (dist[nh][nw] != -1) continue;
        if (i == 0 && g[h][w][1] == 1) continue; //down
        if (i == 1 && g[nh][nw][1] == 1) continue; //up
        if (i == 2 && g[h][w][0] == 1) continue; //right
        if (i == 3 && g[nh][nw][0] == 1) continue; //left
        q.push({nh,nw});
        dist[nh][nw] = dist[h][w] + 1;
      }
    }
    if (dist[H-1][W-1] == -1) dist[H-1][W-1] = 0;
    res_list.push_back(dist[H-1][W-1]);
  }
  for (int res: res_list) cout << res << endl;
  return 0;
}
