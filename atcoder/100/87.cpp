#include <bits/stdc++.h>

using namespace std;

class UnionFind {
  vector<int> parent, rank, count;
public:
  int cannot_go_count;
  UnionFind(int n): parent(n), rank(n,0), count(n ,1), cannot_go_count(n * (n-1) / 2) {
    iota(parent.begin(), parent.end(), 0);
  }
  int find(int a) {
    if (parent[a] != a) parent[a] = find(parent[a]);
    return parent[a];
  }
  void unite(int a, int b) {
    int rootA = find(a); int rootB = find(b);
    if (rootA == rootB) return;
    cannot_go_count -= count[rootA] * count[rootB];
    if (rank[rootA] < rank[rootB]) {
      parent[rootA] = rootB;
      count[rootB] += count[rootA];
    }
    else {
      parent[rootB] = rootA;
      count[rootA] += rootB;
      if (rank[rootA] == rank[rootB]) rank[rootA]++;
    }
  }
};

int main() {
  int N, M; cin >> N >> M;
  vector<int> A(M), B(M);
  for (int i = 0; i < M; ++i) {
    int a, b; cin >> a >> b;
    a--; b--;
    A[i] = a; B[i] = b;
  }
  UnionFind uf(N);
  vector<int> res_list(M);
  for (int i = M - 1; i > -1; --i) {
    res_list[i] = uf.cannot_go_count;
    uf.unite(A[i], B[i]);
  }

  for (int res: res_list) cout << res << endl;
  return 0;
}
