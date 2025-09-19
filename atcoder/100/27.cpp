#include <bits/stdc++.h>

using namespace std;
vector<int> dr = {1,0,-1,0};
vector<int> dc = {0,1,0,-1};

int dfs(vector<vector<int>> &A, int r, int c) {
  int count = 1;
  A[r][c] = 0;
  for (int i = 0; i < 4; ++i) {
    int nr = r + dr[i]; int nc = c + dc[i];
    if (nr < 0 || nr >= A.size() || nc < 0 || nc >= A[0].size()) continue;
    if (A[nr][nc] == 1) {
      count = max(count, 1 + dfs(A, nr, nc));
    }
  }
  A[r][c] = 1;
  return count;
}

int main() {
  int m; cin >> m;
  int n; cin >> n;
  vector<vector<int>> A(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> A[i][j];
    }
  }
  
  int count = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (A[i][j] == 1) {
        int curr_count = dfs(A, i, j);
        count = max(count, curr_count);
      }
    }
  }
  cout << count << endl;
  return 0;
}
