#include <bits/stdc++.h>

using namespace std;

void dfs(int parent, int node, const vector<vector<int>> &tree, vector<int> &X) {
  for (int child: tree[node]) {
    if (child == parent) continue;
    X[child] += X[node];
    dfs(node, child, tree, X);
  }
}

int main() {
  int N, Q; cin >> N >> Q;
  vector<vector<int>> tree(N + 1);
  for (int i = 0; i < N - 1; ++i) {
    int a, b; cin >> a >> b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  vector<int> X(N + 1, 0);
  for (int i = 0; i < Q; ++i) {
    int p, x; cin >> p >> x;
    X[p] += x;
  }

  dfs(-1, 1, tree, X);

  for (int i = 1; i < N; ++i) cout << X[i] << " ";
  cout << X[N] << endl;
  return 0;
}
