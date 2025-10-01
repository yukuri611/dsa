#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};


int Count(int x, int y, vector<string> &S) {
  int c = 0;
  for (int i = 0; i < 4; ++i) {
    int nx = x + dx[i]; int ny = y + dy[i];
    if (nx < 0 || nx >= S.size() || ny < 0 || ny >= S[0].size()) continue;
    if (S[nx][ny] == '#') c++;
  }
  return c;
}

int main() {
  int H, W; cin >> H >> W;
  vector<string> S(H);
  for (int i = 0; i < H; ++i) cin >> S[i];

  vector<pair<int, int>> T;
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      if (S[i][j] == '.' && Count(i,j,S) == 1) {
        T.push_back({i,j});
      }
    }
  }
  for (auto p: T) {
    S[p.first][p.second] = '#';
  }

  for (int _ = 0; _ < H * W; ++_) {
    vector<pair<int, int>> nT;
    for(auto p: T) {
      int x = p.first; int y = p.second;
      for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i]; int ny = y + dy[i];
        if (nx < 0 || nx >= S.size() || ny < 0 || ny >= S[0].size()) continue;
        if (S[nx][ny] == '.' && Count(nx, ny, S) == 1) {
          nT.push_back({nx, ny});
        }
      }
    }
    T = nT;
    for (auto p: T) {
      S[p.first][p.second] = '#';
    }
    if (T.size() == 0) break;
  }
  
  int res = 0;
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      if (S[i][j] == '#') res++;
    }
  }

  cout << res << endl;
  return 0;
}
