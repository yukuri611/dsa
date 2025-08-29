#include <iostream>
#include <vector>

using namespace std;

int directions[8][2] = {{1,0}, {1,-1}, {1, 1}, {0,-1},{0,1},{-1,-1},{-1,0},{-1,1}};

void dfs(vector<vector<int>>& g, int h, int w) {
  for (auto dir: directions) {
    int nh = h + dir[0], nw = w + dir[1];
    if(nh < 0 || nh >= g.size() || nw < 0 || nw >= g[0].size() || !g[nh][nw]) {
      continue;
    }
    g[nh][nw] = 0;
    dfs(g, nh, nw);
  }
}

int main() {
  vector<int> res_list;
  while(true) {
    int w, h; cin >> w >> h;
    if (w == 0 && h == 0) break;
    vector<vector<int>> g(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
      }
    }
    
    int res = 0;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (g[i][j] == 1) {
          g[i][j] = 0;
          dfs(g, i, j);
          res++;
        }
      }
    }
    res_list.push_back(res);
  }
  for (int res: res_list) {
    cout << res << endl;
  }
  return 0;
}
