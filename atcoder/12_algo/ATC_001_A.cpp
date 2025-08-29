#include <iostream>
#include <vector>

using namespace std;

int dw[4] = {0,1,0,-1};
int dh[4] = {1,0,-1,0};

void dfs(vector<string> &graph, vector<vector<bool>> &visited, int h, int w) {
  for (int i = 0; i < 4; ++i) {
    if (h + dh[i] < 0 || h + dh[i] >= visited.size() || w + dw[i] < 0 || w + dw[i] >= visited[0].size() || visited[h + dh[i]][w + dw[i]]) continue;
    if (graph[h + dh[i]][w + dw[i]] != '#') {
      visited[h + dh[i]][w + dw[i]] = true; dfs(graph, visited, h + dh[i], w + dw[i]);
    }
  }
}

int main() {
  int H, W; cin >> H >> W;
  vector<string> graph(H);
  for (int i = 0; i < H; ++i) cin >> graph[i];

  int start_h, start_w, goal_h, goal_w;
  for (int h = 0; h < H; ++h) {
    for (int w = 0; w < W; ++w) {
      if (graph[h][w] == 's') {
        start_h = h; start_w = w;
      }
      if (graph[h][w] == 'g') {
        goal_h = h; goal_w = w;
      }
    }
  }

  vector<vector<bool>> visited(H, vector<bool>(W, false));
  visited[start_h][start_w] = true;
  dfs(graph, visited, start_h, start_w);
  if (visited[goal_h][goal_w]) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
