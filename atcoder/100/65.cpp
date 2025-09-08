#include <bits/stdc++.h>

using namespace std;

 
struct Edge{
  int u, v; 
  int cost;
  Edge(int u, int v, int cost) : u(u), v(v), cost(cost) {}
  bool operator<(const Edge& other) const {
    return cost < other.cost;
  }
};

class UnionFind{
  vector<int> parent;
  vector<int> rank;

public:
  UnionFind(int n): parent(n), rank(n,0) {
    for (int i = 0; i < n; ++i) {
      parent[i] = i;
    }
  }

  int find(int n) {
    if (parent[n] == n) return n;
    parent[n] = find(parent[n]);
    return parent[n];
  }

  void unite(int x, int y) {
    int parentX = find(x);
    int parentY = find(y);
    if (parentX != parentY) {
      if (rank[parentX] < rank[parentY]) {
        parent[parentX] = parentY;
      }
      else {
        parent[parentY] = parentX;
        if (rank[parentX] == rank[parentY]) rank[parentX]++;
      }
    }
  }
};

long long kruskal(int N, int K, vector<Edge> edges) {
  sort(edges.begin(), edges.end());
  UnionFind uf(N);
  long long total_cost = 0;
  int edge_count = 0;
  if (N <= K) return 0;
  for (auto edge: edges) {
    int u = edge.u; int v = edge.v; int c = edge.cost;
    if (uf.find(u) == uf.find(v)) continue; //既に同じ木に含まれる
    uf.unite(u,v);
    total_cost += c;
    edge_count++;
    if (edge_count == N - K) break;
  }
  return total_cost;
}

int main(){
  int N, M, K; cin >> N >> M >> K;
  vector<Edge> edges; 
  for (int i = 0; i < M; ++i) {
    int a, b, c; cin >> a >> b >> c;
    edges.push_back(Edge(a-1, b-1, c));
  } 

  long long res = kruskal(N, K, edges);
  cout << res << endl;
  return 0;

}
