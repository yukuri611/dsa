#include <iostream>
#include <vector>
using namespace std;

bool dfs(int i, int j, vector<vector<char>> &grid);
int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> grid(H, vector<char>(W));
  for(int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> grid[i][j];
    }
  }

  int s_i, s_j;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (grid[i][j] == 's') {
        s_i = i;
        s_j = j;
      }
    }
  }

  bool res = dfs(s_i, s_j, grid);
  if (res) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
  return 0;
}

bool dfs(int i, int j, vector<vector<char>> &grid) {
  if (grid[i][j] == 'g') {
    return true;
  }

  pair<int, int> directions[4] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
  bool res = false;
  for (pair<int, int> direction: directions) {
    if (i+direction.first < 0 or i+direction.first >= grid.size() or j+direction.second < 0 or j+direction.second >= grid[0].size() or grid[i][j] == '#' or grid[i][j] == 'T') {
      continue;
    }
    char temp = grid[i+direction.first][j+direction.second];
    grid[i+direction.first][j+direction.second] = 'T';
    if (dfs(i + direction.first, j + direction.second, grid)){
      grid[i+direction.first][j+direction.second] = temp;
      return true;
    }
    grid[i+direction.first][j+direction.second] = temp;
  }
  return false;
}
