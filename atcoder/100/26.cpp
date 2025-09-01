#include <vector>
#include <iostream>

using namespace std;

void dfs(vector<vector<int>> &tree, vector<long long> &counter, int v, int p) {
  for(int child: tree[v]) {
    if (child == p) continue; 
    counter[child] += counter[v];
    dfs(tree, counter, child, v);
  }
  return;
}

int main() {
  int N, Q; cin >> N >> Q;
  vector<vector<int>> tree(N + 1);
  for (int _ = 0; _ < N - 1; ++_) {
    int a, b; cin >> a >> b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  vector<long long> counter(N + 1, 0);
  for (int _ = 0; _ < Q; _++) {
    long long p, x; cin >> p >> x;
    counter[p] += x;
  }

  dfs(tree, counter, 1, -1);
  for (int i = 1; i <= N; ++i) cout << counter[i] << " ";
  cout << endl;
  return 0;
}
