#include <bits/stdc++.h>

using namespace std;
class UnionFind{ 
  vector<int> parent, rank;

public:
  UnionFind(int n): parent(n), rank(n,0) {
    iota(parent.begin(), parent.end(), 0);
  }

  int find(int a) {
    if (parent[a] != a) parent[a] = find(parent[a]);
    return parent[a];
  }

  void unite(int a, int b) {
    int roota = find(a);
    int rootb = find(b);
    if (roota == rootb) return;
    if (rank[roota] > rank[rootb]) {
      parent[rootb] = roota;
    }
    else {
      parent[roota] = rootb;
      if (rank[roota] == rank[rootb]) {
        rank[rootb]+= 1;
      }
    }
  }

  bool same(int a, int b) {
    return find(a) == find(b);
  }
};

int main() {
  int n, q; cin >> n >> q;
  UnionFind uf(n);
  vector<int>res_list;
  for (int i = 1; i <= q; ++i) {
    int com, x, y; cin >> com >> x >> y;
    if (com) {
      if (uf.same(x,y)) res_list.push_back(1);
      else res_list.push_back(0);
    }
    else {
      uf.unite(x, y);
    }
  }
  for (int res : res_list) cout << res << endl;
  return 0;
}
