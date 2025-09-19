#include <bits/stdc++.h>

using namespace std;

int main() {
  int m; cin >> m;
  vector<int> conX(m);
  vector<int> conY(m);
  for (int i = 0; i < m; ++i) {
    cin >> conX[i] >> conY[i];
  }
  int n; cin >> n;
  vector<vector<int>> grid(1e6 + 1);
  vector<int> X(n);
  vector<int> Y(n);
  for (int i = 0; i < n; ++i) {
    int x, y; cin >> x >> y;
    grid[x].push_back(y);
    X[i] = x; Y[i] = y;
  }
  for (int i = 0; i < 1e6 + 1; ++i) {
    sort(grid[i].begin(), grid[i].end());
  }

  for (int i = 0; i < n; ++i) {
    int dx = X[i] - conX[0];
    int dy = Y[i] - conY[0];
    bool valid = true;
    for (int j = 1; j < m; ++j) {
      int x = conX[j] + dx; int y = conY[j] + dy;
      if (x < 0 || x > 1e6 || y < 0 || y > 1e6) {
        valid = false;
        break;
      }
      auto it = lower_bound(grid[x].begin(), grid[x].end(), y);
      if (it == grid[x].end() || *it != y) {
        valid = false;
        break;
      }
    }
    if (valid) {
      cout << dx << " " << dy << endl;
      return 0;
    }
  }

  return 0;

}
