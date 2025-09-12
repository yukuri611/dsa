#include <bits/stdc++.h>

using namespace std;
using LL = long long;

struct Edge{
  int u, v, w;
  Edge(int u, int v, int w) : u(u), v(v), w(w) {}
  bool operator>(const Edge& e) const{
    return w > e.w;
  }
};

class UnionFind{
  vector<int> parent, rank;
public:
  UnionFind(int n) : parent(n), rank(n, 0){
    iota(parent.begin(), parent.end(), 0);
  }
  int find(int a) {
    if (parent[a] != a) parent[a] = find(parent[a]);
    return parent[a];
  }

  void unite(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);
    if (rootA == rootB) return;
    if (rank[rootB] > rank[rootA]) {
      parent[rootA] = rootB;
    }
    else {
      parent[rootB] = rootA;
      if(rank[rootA] == rank[rootB]) {
        rank[rootA]++;
      }
    }
  }

  bool same(int a, int b) {
    return find(a) == find(b);
  }
};

int main() {
  int N; cin >> N;
  vector<int> X(N), Y(N);
  for (int i = 0; i < N; ++i) cin >> X[i] >> Y[i];

  priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
  vector<int> id(N);
  //xによって追加
  iota(id.begin(), id.end(), 0);
  sort(id.begin(), id.end(), [&X](int i, int j){return X[i] < X[j];});
  for (int i = 0; i < N - 1; ++i) {
    int u = id[i]; int v= id[i + 1];
    int w = X[v] - X[u];
    pq.push(Edge(u,v,w));
  }
  //yによって追加
  iota(id.begin(), id.end(), 0);
  sort(id.begin(), id.end(), [&Y](int i, int j){return Y[i] < Y[j];});
  for (int i = 0; i < N - 1; ++i) {
    int u = id[i]; int v= id[i + 1];
    int w = Y[v] - Y[u];
    pq.push(Edge(u,v,w));
  }

  UnionFind uf(N);
  LL res = 0;
  int count = 0;
  while(!pq.empty()) {
    Edge e = pq.top();
    pq.pop();
    if (uf.same(e.u, e.v)) continue;
    uf.unite(e.u, e.v);
    res += e.w;
    count++;
    if (count == N-1) break;
  }

  cout << res << endl;
  return 0;

}
