#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G;
vector<int> dp;

int dfs(int i) {
  if (dp[i] != 0) return dp[i];
  int d = 0;
  for (int v: G[i]) {
    d = max(d, 1 + dfs(v));
  }
  dp[i] = d;
  return dp[i];
}

int main() {
  int N, M; cin >> N >> M;
  G.resize(N);
  for (int i = 0; i < M; ++i) {
    int x, y; cin >> x >> y;
    x--; y--;
    G[x].push_back(y);
  }
  dp.assign(N, 0);
  queue<int> q;
  for (int i = 0; i < N; ++i) {
    dfs(i);
  }

  cout << *(max_element(dp.begin(), dp.end())) << endl;
  return 0;
}
