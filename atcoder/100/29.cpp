#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> dx = {1,0,-1,0};
vector<int> dy = {0,1,0,-1};

int main() {
  int R, C; cin >> R >> C;
  int sy, sx; cin >> sy >> sx;
  int gy, gx; cin >> gy >> gx;
  sy--; sx--; gy--; gx--;

  vector<vector<char>> graph(R, vector<char>(C));
  for (int y = 0; y < R; ++y) {
    for (int x = 0; x < C; ++x) {
      cin >> graph[y][x];
    }
  }

  vector<vector<int>> dist(R, vector<int>(C, -1));
  queue<pair<int, int>> q;
  dist[sy][sx] = 0;
  q.push({sy,sx});
  while(!q.empty()) {
    pair<int, int> p = q.front();
    q.pop();
    int y, x; y = p.first; x = p.second;
    for (int i = 0; i < 4; ++i) {
      int ny, nx;  ny = y + dy[i]; nx = x + dx[i];
      if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
      if (dist[ny][nx] != -1) continue;
      if (graph[ny][nx] == '#') continue;
      dist[ny][nx] = dist[y][x] + 1;
      q.push({ny,nx});
    }
  }

  cout << dist[gy][gx] << endl;
  return 0;

  
}
