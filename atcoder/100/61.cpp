#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, M; cin >> N >> M;
  vector<vector<int>> dist(N + 1, vector<int>(N+1, INT_MAX));
  for (int i = 1; i <= N; ++i) dist[i][i] = 0;
  for (int i = 0; i < M; ++i) {
    int a, b, t; cin >> a >> b >> t;
    dist[a][b] = t;
    dist[b][a] = t;
  }

  for (int k = 1; k <= N; ++k) {
    for (int i = 1; i <= N; ++i) {
      for (int j = 1; j <= N; ++j) {
        if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) continue;
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  int res = INT_MAX;
  for (int i = 1; i <= N; ++i) {
    int curr = -1;
    for (int j = 1; j <= N; ++j) {
      curr = max(curr, dist[i][j]);
    }
    res = min(res, curr);
  }
  cout << res << endl;
  return 0;
}
