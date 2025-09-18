//座標圧縮からのdfs

#include <bits/stdc++.h>
using namespace std;

vector<int> dh = {1,0,-1,0};
vector<int> dw = {0,1,0,-1};

int main() {
  int W, H; cin >> W >> H;
  int n; cin >> n;
  vector<int> X1(n + 4), X2(n + 4), Y1(n + 4), Y2(n + 4);
  set<int> setX, setY;
  for (int i = 0; i < n; ++i) {
    cin >> X1[i] >> Y1[i] >> X2[i] >> Y2[i];
    setX.insert(X1[i]); setX.insert(X2[i]); setY.insert(Y1[i]); setY.insert(Y2[i]);
  }
  //外側を四枚のマスキングテープで覆う
  X1[n] = -1; Y1[n] = H; X2[n] = W + 1; Y2[n] = H + 1;//上
  X1[n + 1] = -1; Y1[n + 1] = -1; X2[n + 1] = W + 1; Y2[n + 1] = 0; //下
  X1[n + 2] = -1; Y1[n + 2] = 0; X2[n + 2] = 0; Y2[n + 2] = H; //左
  X1[n + 3] = W; Y1[n + 3] = 0; X2[n + 3] = W + 1; Y2[n + 3] = H; //右
  for (int i = n; i < n + 4; ++i) {
    setX.insert(X1[i]); setX.insert(X2[i]); setY.insert(Y1[i]); setY.insert(Y2[i]);
  }
  vector<int> uX(setX.begin(), setX.end()), uY(setY.begin(), setY.end());
  sort(uX.begin(), uX.end()); sort(uY.begin(), uY.end());

  int nW, nH; nW = uX.size(); nH = uY.size();
  vector<vector<int>> grid(nH, vector<int>(nW,0));
  for (int i = 0; i < n + 4; ++i) {
    int x1 = lower_bound(uX.begin(), uX.end(), X1[i]) - uX.begin();
    int x2 = lower_bound(uX.begin(), uX.end(), X2[i]) - uX.begin();
    int y1 = lower_bound(uY.begin(), uY.end(), Y1[i]) - uY.begin();
    int y2 = lower_bound(uY.begin(), uY.end(), Y2[i]) - uY.begin();
    grid[y1][x1] += 1;
    grid[y2][x1] -= 1;
    grid[y1][x2] -= 1;
    grid[y2][x2] += 1;
  }
  
  for (int i = 0; i < nH; ++i) {
    for (int j = 1; j < nW; ++j) {
      grid[i][j] += grid[i][j-1];
    }
  }
  for (int j = 0; j < nW; ++j) {
    for (int i = 1; i < nH; ++i) {
      grid[i][j] += grid[i-1][j];
    }
  }
  long long res = 0; 
  for (int i = 0; i < nH-1; ++i) {
    for (int j = 0; j < nW-1; ++j) {
      if (grid[i][j] == 0) {
        res++;
        queue<pair<int, int>> q;
        q.push({i,j});
        grid[i][j] = 1;
        while(!q.empty()) {
          auto p = q.front();
          q.pop();
          int h = p.first;
          int w = p.second;
          for (int i = 0; i < 4; ++i) {
            int nh = h + dh[i];
            int nw = w + dw[i];
            if (nh < 0 || nh >= grid.size() || nw < 0 || nw >= grid[0].size()) continue;
            if (grid[nh][nw] != 0) continue;
            q.push({nh, nw});
            grid[nh][nw] = 1;
          }
        }
      }
    }
  }

  cout << res << endl;
  return 0;
}
