#include <bits/stdc++.h>

using namespace std;

int dijkstra(vector<vector<pair<int, int>>> &G, int a, int b) {
  vector<int> dist(G.size(), INT_MAX);
  dist[a] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, a});
  while(!pq.empty()) {
    int d = pq.top().first;
    int u = pq.top().second;
    pq.pop();
    if (d > dist[u]) continue;
    if (u == b) return d;
    for (const auto p: G[u]) {
      int v = p.first;
      int w = p.second;
      if (d + w < dist[v]) {
        dist[v] = d + w;
        pq.push({dist[v], v});
      }
    }
  }
  return -1;
}

int main() {
  int n, k; cin >> n >> k;
  vector<vector<pair<int,int>>> G(n + 1); //1-indexed
  vector<int> res_list;
  for (int _ = 0; _ < k; ++_) {
    int f; cin >> f;
    if (f) {
      // 新しい船の情報
      int c, d, e; cin >> c >> d >> e;
      G[c].push_back({d,e});
      G[d].push_back({c,e});
    }
    else {
      int a, b; cin >> a >> b;
      int dist = dijkstra(G, a, b);
      res_list.push_back(dist);
    }
  }

  for (int res: res_list) cout << res << endl;
  return 0;
}
