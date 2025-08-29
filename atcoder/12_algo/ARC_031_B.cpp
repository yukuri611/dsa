#include <iostream>
#include <vector>

using namespace std;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
void dfs(const vector<string> &g, vector<vector<bool>> &visited, int x, int y) {
  for (int i = 0; i < 4; ++i) {
    int nx = x + dx[i], ny = y + dy[i];
    if (nx < 0 || nx >= g[0].length() || ny < 0 || ny >= g.size() || g[ny][nx] == 'x' || visited[ny][nx] == true) {
      continue;
    }
    visited[ny][nx] = true;
    dfs(g, visited, nx, ny);
  }
}

bool check(const vector<string> &g, vector<vector<bool>> &visited) {
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      if(g[i][j] == 'x') continue;
      if (!visited[i][j]) return false;
    }
  }
  return true;
}
int main() {
  vector<string>g(10);
  for (int i = 0; i < 10; ++i) {
    cin >> g[i];
  }
  
  for(int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j){
      if (g[i][j] == 'x') {
        vector<vector<bool>> visited(10, vector<bool>(10, false));
        visited[i][j] = true;
        g[i][j] = 'o';
        dfs(g, visited, j, i);
        if (check(g, visited)) {
          cout << "YES" << endl;
          return 0;
        }
        g[i][j] = 'x';
      }
    }
  }

  cout << "NO" << endl;
}
