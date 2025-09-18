#include <bits/stdc++.h>

using namespace std;

vector<int> dr = {1,0,-1,0};
vector<int> dc = {0,1,0,-1};

class UnionFind {
public:
  vector<int> parent;
  void init(int n) {
    parent.resize(n);
    iota(parent.begin(), parent.end(), 0);
  }
  int find(int a) {
    if (parent[a] != a) parent[a] = find(parent[a]);
    return parent[a];
  }
  void unite(int a, int b) {
    a = find(a); b = find(b);
    if (a == b) return;
    parent[b] = a;
  }

  bool same(int a, int b) {
    return find(a) == find(b);
  }
};

vector<bool> grid;
int H, W; 
UnionFind uf;

void query1(int r, int c) {
  grid[r * W + c] = true;
  for (int i = 0; i < 4; ++i) {
    int nr = r + dr[i]; int nc = c + dc[i];
    if (nr < 0 || nr >= H || nc < 0 || nc >= W) continue;
    if (grid[nr * W + nc]) uf.unite(r * W + c, nr * W + nc);
  }
}

bool query2(int a, int b) {
  if (!grid[a] || !grid[b]) return false;
  return uf.same(a, b);
}


int main() {
  cin >> H >> W;
  grid.assign(H*W, false);
  int Q; cin >> Q;
  uf.init(H * W);
  vector<string> res_list;
  for (int i = 0; i < Q; ++i) {
    int t; cin >> t;
    if (t == 1) {
      int r, c; cin >> r >> c;
      --r; --c;
      query1(r, c);
    }
    else {
      int ra, ca, rb, cb; cin >> ra >> ca >> rb >> cb;
      --ra; --ca; --rb; --cb;
      bool Answer = query2(ra * W + ca, rb * W + cb);
      if (Answer) {
        res_list.push_back("Yes");
      }
      else {
        res_list.push_back("No");
      }
    }
  }
  for (string s: res_list) cout << s << endl;
  return 0;
}

