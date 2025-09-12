#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, M; cin >> N >> M;
  vector<vector<int>> distance(N, vector<int>(N,INT_MAX));
  for (int i = 0; i < M; ++i) {
    int a, b, t; cin >> a >> b >> t;
    a--; b--;
    distance[a][b] = t;
    distance[b][a] = t;
  }
  for (int i = 0; i < N; ++i) distance[i][i] = 0;

  for (int k = 0; k < N; ++k) {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (distance[i][k] == INT_MAX || distance[k][j] == INT_MAX) continue;
        distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
      }
    }
  }
  
  int res = INT_MAX;
  for (int i = 0; i < N; ++i) {
    int curr = 0;
    for (int j = 0; j < N; ++j) {
      curr = max(curr, distance[i][j]);
    }
    res = min(res, curr);
  }

  cout << res <<endl;
  return 0;
}
