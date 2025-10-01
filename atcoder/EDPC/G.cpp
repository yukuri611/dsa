#include <bits/stdc++.h>

using namespace std;

vector<int> memo;
vector<vector<int>> G;
int dfs(int u) {
  if (memo[u] != -1) return memo[u];
  int dist = 0;
  for (int v: G[u]) {
    dist = max(dist, 1 + dfs(v));
  }
  memo[u] = dist;
  return memo[u];
}

int main() {
  int N, M; cin >> N >> M;
  G.resize(N + 1);
  memo.assign(N + 1, -1);
  for (int i = 0; i < M; ++i) {
    int x, y; cin >> x >> y;
    G[x].push_back(y);
  }

  int res = 0;
  for (int i = 1; i <= N; ++i) {
    if (memo[i] == -1) {
      dfs(i);
    }
    res = max(res, memo[i]);
  }

  cout << res << endl;
  return 0;
}
