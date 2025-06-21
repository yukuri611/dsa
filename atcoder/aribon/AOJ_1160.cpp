#include <vector>
#include <iostream>

using namespace std;

int directions[8][2] = {{1,0}, {-1, 0}, {0,1}, {0,-1}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};

void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &visited) {
  for (auto& dir: directions) {
    int ni = i + dir[0];
    int nj = j + dir[1];
    if (0 <= ni && ni < grid.size() && 0 <= nj && nj < grid[0].size() && grid[ni][nj] == 1 && !visited[ni][nj]) {
      visited[ni][nj] = true;
      dfs(ni, nj, grid, visited);
    }
  }
}

int main() {
  int w, h;
  vector<int> res_list;
  while (true) {
    cin >> w >> h;
    if (w == 0 && h == 0) {
      break;
    }
    vector<vector<int>> grid(h, vector<int>(w, 0));
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        cin >> grid[i][j];
      }
    }
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    int count = 0;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (grid[i][j] == 1 && !visited[i][j]) {
          visited[i][j] = true;
          dfs(i, j, grid, visited);
          count += 1;
        }
      }
    }
    res_list.push_back(count);
  }
  for (int res: res_list) {
    cout << res << endl;
  }
  return 0;
}
