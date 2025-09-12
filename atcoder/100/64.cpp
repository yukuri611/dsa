#include <bits/stdc++.h>

using namespace std;

struct Edge{
  int u, v, w;
  Edge(int u, int v, int w) : u(u), v(v), w(w){}

  bool operator<(const Edge &e) const {
    return w < e.w;
  }

  bool operator>(const Edge &e) const {
    return w > e.w;
  }
};

class UnionFind{
  vector<int> parent, rank;

public:
  UnionFind(int n): parent(n), rank(n, 0) {
    iota(parent.begin(), parent.end(), 0);
  }
  int find(int n) {
    if (parent[n] != n) parent[n] = find(parent[n]);
    return parent[n];
  }
  void unite(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);
    if (rootA == rootB) return;
    if (rank[rootA] < rank[rootB]) {
      parent[rootA] = rootB;
    }
    else {
      parent[rootB] = rootA;
      if (rank[rootA] == rank[rootB]) {
        rank[rootA] ++;
      }
    }
  }

  bool same(int a, int b) {
    return find(a) == find(b);
  }
};

int main() {
  int V, E; cin >> V >> E;
  priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
  for (int i = 0; i < E; ++i) {
    int s, t, w; cin >> s >> t >> w;
    pq.push(Edge(s, t, w));
  }
  
  UnionFind uf(V);
  int count = 1;
  int res = 0;
  while(!pq.empty()) {
    Edge e = pq.top();
    pq.pop();
    if (uf.same(e.u, e.v)) continue;
    else {
      uf.unite(e.u, e.v);
      res += e.w;
      count++;
      if (count == V) break;
    }
  }

  cout << res << endl;
  return 0;
}
