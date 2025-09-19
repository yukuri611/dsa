#include <bits/stdc++.h>

using namespace std;

int H, W; 
vector<int> dr = {0,1,0,-1};
vector<int> dc = {1,0,-1,0};
vector<string> S;
vector<vector<int>> dist;
int white_count = 0;

void bfs() {
  queue<pair<int, int>> q;
  q.push({0,0});
  dist[0][0] = 0;
  while(!q.empty()) {
    auto p = q.front();
    q.pop();
    int r = p.first; int c = p.second;
    for (int i = 0; i < 4; ++i) {
      int nr = r + dr[i]; int nc = c + dc[i];
      if (nr < 0 || nr >= H || nc < 0 || nc >= W) continue;
      if (S[nr][nc] == '#') continue;
      if (dist[nr][nc] != INT_MAX) continue;
      q.push({nr,nc});
      dist[nr][nc] = dist[r][c] + 1;
    }
  }
}

int main() {
  cin >> H >> W; 
  S.resize(H);
  dist.resize(H, vector<int>(W, INT_MAX));
  for (int i = 0; i < H; ++i) {
    cin >> S[i];
    for (int j = 0; j < W; ++j) {
      if (S[i][j] == '.') white_count++;
    }
  }

  bfs();
  if (dist[H-1][W-1] == INT_MAX) {
    cout << -1 << endl;
  }
  else {
    int erase_count = white_count - (dist[H - 1][W - 1] + 1);
    cout << erase_count << endl;
  }
  return 0;
}
