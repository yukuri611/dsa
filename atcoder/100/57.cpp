#include <bits/stdc++.h>

using namespace std;

int dijkstra(vector<vector<pair<int, int>>> G, int s, int t) {
  int N = G.size();
  vector<int> total_cost(N, INT_MAX);
  total_cost[s] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, s});
  while(!pq.empty()) {
    auto p = pq.top();
    pq.pop();
    int cost = p.first;
    int u = p.second;
    if (total_cost[u] < cost) continue;
    if (u == t) return cost;
    for (auto e: G[u]) {
      int v = e.first;
      int new_cost = cost + e.second;
      if (total_cost[v] <= new_cost) continue;
      total_cost[v] = new_cost;
      pq.push({new_cost,v});
    }
  }

  return -1;
}
int main() {
  int n, k; cin >> n >> k;
  vector<vector<pair<int, int>>> G(n);

  vector<int> res_list;
  for (int _ = 0; _ < k; ++_) {
    int f; cin >> f;
    if (f == 0) {
      int a, b; cin >> a >> b;
      a--; b--;
      int cost = dijkstra(G, a, b);
      res_list.push_back(cost);
    }
    else {
      int c, d, e; cin >> c >> d >> e;
      c--; d--;
      G[c].push_back({d, e});
      G[d].push_back({c,e});
    }
  }
  for (int res: res_list) cout << res <<endl;
  return 0;

}
