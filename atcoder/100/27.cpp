#include <iostream>
#include <vector>

using namespace std;
vector<int> di = {1, 0, -1, 0};
vector<int> dj = {0, 1, 0, -1};
int dfs(vector<vector<int>> f, int i, int j) {
  f[i][j] = 0;
  int res = 1;
  for (int k = 0; k < 4; ++k) {
    int ni = i + di[k];
    int nj = j + dj[k];
    if (ni < 0 || ni >= f.size() || nj < 0 || nj >= f[0].size() || !f[ni][nj]) continue;
    res = max(res, 1 + dfs(f, ni, nj));
  }
  f[i][j] = 1;
  return res;

}

int main() {
  int m, n; cin >> m >> n;
  vector<vector<int>> f(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) cin >> f[i][j];
  }

  int res = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if(f[i][j]) res = max(res, dfs(f, i, j));
    }
  }

  cout << res << endl;
  return 0;
}
