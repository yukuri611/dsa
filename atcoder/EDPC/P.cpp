#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll mod = 1e9 + 7;

vector<vector<int>> Tree;

pair<ll, ll> dfs(int node, int parent) {
  int all_white = 1; int all = 1; //childが全部白の組み合わせ、全組み合わせ数
  for (int child: Tree[node]) {
    if (child == parent) continue;
    auto p = dfs(child, node);
    all_white = (all_white * p.first) % mod;
    all = (all * (p.first + p.second)) % mod;
  }
  return {all, all_white}; //nodeが白になる通り数 = all, nodeが黒になる = all_white
}

int main() {
  int N; cin >> N;
  Tree.resize(N);
  for (int i = 0; i < N - 1; ++i) {
    int x, y; cin >> x >> y;
    x--; y--;
    Tree[x].push_back(y);
    Tree[y].push_back(x);
  }

  auto p = dfs(0,-1);

  cout << (p.first + p.second) % mod << endl;
  return 0;
}
