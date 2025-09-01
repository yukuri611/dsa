#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
  int n; cin >> n;
  vector<vector<int>> G(n + 1);
  for (int i = 0; i < n; ++i) {
    int u, k; cin >> u >> k;
    for (int j = 0; j < k; ++j) {
      int v; cin >> v;
      G[u].push_back(v);
    }
  }

  vector<int> dist(n + 1, - 1);
  dist[1] = 0;
  queue<int> q;
  q.push(1);
  while(!q.empty()) {
    int node = q.front();
    q.pop();
    for (int next_node: G[node]) {
      if (dist[next_node] != -1) continue;
      dist[next_node] = dist[node] + 1;
      q.push(next_node);
    }
  }
  for (int i = 1; i < n + 1; ++i) {
    cout << i << " " << dist[i] << endl;
  }
  return 0;

}
