#include <bits/stdc++.h>

using namespace std;

class UnionFind{
  vector<int> parent, rank;

public:
  UnionFind(int n) : parent(n + 1), rank(n + 1, 0) {
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
    if (rank[rootB] > rank[rootA]) {
      parent[rootA] = rootB;
    }
    else {
      parent[rootB] = rootA;
      if (rank[rootB] == rank[rootA]) {
        rank[rootA]++;
      }
    }
  }

  bool same(int a, int b) {
    return find(a) == find(b);
  }
};

int main() {
  int N, M;
  cin >> N >> M;
  vector<pair<int,int>> edge(M);
  for (int i = 0; i < M; ++i) {
    int a, b; cin >> a >> b;
    edge[i] = {a,b};
  }

  int res = 0;

  for (int remove = 0; remove < M; ++remove) {
    UnionFind uf(N);
    for (int i = 0; i < M; ++i) {
      if (i == remove) continue;
      int a, b; a = edge[i].first; b = edge[i].second;
      uf.unite(a,b);
    }
    for (int i = 2; i <= N; ++i) {
      if (!uf.same(1, i)) {
        res += 1;
        break;
      }
    }
  }
  cout << res << endl;
  return 0;
}
