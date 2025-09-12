#include <bits/stdc++.h>

using namespace std;

struct Edge{
  int v,cost;
  Edge(int v, int cost) : v(v), cost(cost) {}
  bool operator<(const Edge &e) {
    return cost < e.cost;
  }
};

int main() {
  int V, E, r; cin >> V >> E >> r;
  vector<vector<Edge>> edges(V);
  for (int i = 0; i < E; ++i) {
    int u, v, cost; cin >> u >> v >> cost;
    edges[u].push_back({v,cost});
  }

  vector<int> distance(V, INT_MAX);
  distance[r] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0,r});
  while (!pq.empty()) {
    auto p = pq.top();
    pq.pop();
    int u = p.second;
    int curr_cost = p.first;
    if (curr_cost > distance[u]) continue;
    for (Edge e: edges[u]) {
      int total_cost = curr_cost + e.cost;
      int v = e.v;
      if (distance[v] > total_cost) {
        distance[v] = total_cost;
        pq.push({total_cost,v});
      }
    }
  }

  int sum = 0;
  for (int d: distance) {
    if (d == INT_MAX) cout << "INF" << endl;
    else cout << d << endl;
  }
  return 0;
}
