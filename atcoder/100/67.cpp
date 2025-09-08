#include <bits/stdc++.h>

using namespace std;
using LL = long long;

struct Edge {
  int u, v;
  int cost;
  Edge(int u, int v, int cost) : u(u), v(v), cost(cost) {}
};

class UnionFind {
public:
  vector<int> parent, rank;
  UnionFind(int n) : parent(n), rank(n,0) {
    iota(parent.begin(), parent.end(), 0);
  }

  int find(int n) {
    if (parent[n] != n) {
      parent[n] = find(parent[n]);
    }
    return parent[n];
  }

  void unite(int a, int b) {
    int pa = find(a); int pb = find(b);
    if (pa == pb) return;
    if (rank[pa] < rank[pb]) {
      parent[pa] = pb;
    }
    else {
      parent[pb] = pa;
      if (rank[pa] == rank[pb]) rank[pa]++;
    }
  }
};

LL kruscal(int N, vector<Edge> edges) {
  UnionFind uf(N);
  sort(edges.begin(), edges.end(), [&](Edge a, Edge b){return a.cost < b.cost;});
  int edge_count = 0;
  LL total_cost = 0;
  for (Edge edge: edges) {
    int u,v,cost; u = edge.u; v = edge.v; cost = edge.cost;
    if (uf.find(u) == uf.find(v)) continue;
    uf.unite(u, v);
    total_cost += cost;
    edge_count++;
    if (edge_count == N - 1) break;
  }
  return total_cost;
}
int main() {
  int N; cin >> N;
  vector<int> x(N), y(N);
  for (int i = 0; i < N; ++i) cin >> x[i] >> y[i];

  vector<Edge> edges;
  vector<int> ids(N);
  iota(ids.begin(), ids.end(), 0);
  sort(ids.begin(), ids.end(), [&](int i, int j) {return x[i] < x[j];});
  for (int i = 0; i < ids.size() - 1; ++i) {
    int u = ids[i]; int v = ids[i+1]; int cost = abs(x[u] - x[v]);
    edges.push_back(Edge(u, v, cost));
  }

  iota(ids.begin(), ids.end(), 0);
  sort(ids.begin(), ids.end(), [&](int i, int j) {return y[i] < y[j];});
  for (int i = 0; i < ids.size() - 1; ++i) {
    int u = ids[i]; int v = ids[i+1]; int cost = abs(y[u] - y[v]);
    edges.push_back(Edge(u, v, cost));
  }

  LL res = kruscal(N, edges);
  cout << res << endl;

  return 0;
}
