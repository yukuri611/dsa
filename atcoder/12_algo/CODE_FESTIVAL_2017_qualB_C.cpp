#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<vector<int>> &g, vector<int> &color, int u, int c) {
  color[u] = c;
  for (int v: g[u]) {
    if (color[v] == -1 && !dfs(g, color, v, 1 - color[u])) return false;
    else if (color[v] != 1 - color[u]) return false;
  }
  return true;
}
int main() {
  long long N, M; cin >> N >> M;
  vector<vector<int>> g(N + 1);
  for (int i = 0; i < M; ++i) {
    int A, B; cin >> A >> B;
    g[A].push_back(B);
    g[B].push_back(A);
  }

  vector<int> color(N + 1, -1);
  bool bipartite = dfs(g, color, 1, 0);
  if (bipartite) {
    long long count = 0;
    for (int i = 1; i < N + 1; ++i) {
      if (color[i] == 1) count++;
    }
    cout << count * (N - count) - M << endl; 
  }
  else {
    cout << N * (N - 1) / 2 - M << endl;
  }

  return 0;
}
