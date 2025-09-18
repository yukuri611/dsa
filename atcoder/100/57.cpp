#include <bits/stdc++.h>

using namespace std;

int dijkstra(vector<vector<pair<int, int>>> G, int s, int e) {
  if (s == e) return 0;
  vector<bool> visited(G.size(), false);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0,s});
  while (!pq.empty()) {
    auto p = pq.top();
    pq.pop();
    int u = p.second; int curr_cost = p.first;
    if (u == e) return curr_cost;
    if (visited[u]) continue;
    visited[u] = true;
    for (auto p: G[u]) {
      int v = p.first; int new_cost = curr_cost + p.second;
      if (!visited[v]) {
        pq.push({new_cost, v});
      }
    }
  }
  return -1;
}

int main() {
  int n, k; cin >> n >> k;
  vector<vector<pair<int, int>>> G(n + 1);
  vector<int> res_list;
  for (int _ = 0; _ < k; ++_) {
    int f; cin >> f;
    if (f == 0) {
      int a, b; cin >> a >> b;
      int cost = dijkstra(G, a, b);
      res_list.push_back(cost);
    }
    else {
      int c, d, e; cin >> c >> d >> e;
      G[c].push_back({d,e});
      G[d].push_back({c,e});
    }
  }
  for (int res: res_list) cout << res << endl;
  return 0;
}
