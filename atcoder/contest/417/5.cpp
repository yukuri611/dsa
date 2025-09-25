#include <bits/stdc++.h>

using namespace std;
#define rep(i, k, n) for(int i = k; i < n; ++i)

vector<bool> visited1;
vector<bool> seen2;
vector<int> path;

bool canReach(vector<vector<int>>& G, int s, int d) {
  queue<int> q;
  q.push(s);
  while(!q.empty()) {
    int n = q.front();
    q.pop();
    if (n == d) return true;
    for (int child: G[n]) {
      if (visited1[child] || seen2[child]) continue;
      seen2[child] = true;
      q.push(child);
    }
  }
  return false;
}
void solve(vector<vector<int>> &G, int s, int d) {
  int currNode = s;
  path.push_back(s);
  while (currNode != d) {
    for (int nextNode: G[currNode]) {
      if (visited1[nextNode]) continue;
      seen2.assign(G.size() + 1, false);
      if (canReach(G, nextNode, d)) {
        path.push_back(nextNode);
        visited1[nextNode] = true;
        currNode = nextNode;
        break;
      }
    }
  }
  for (int n: path) cout << n << " ";
  cout << endl;
}

int main() {
  int T; cin >> T;
  rep(t, 0, T) {
    int N, M, X, Y; cin >> N >> M >> X >> Y;
    vector<vector<int>> G(N + 1);
    rep(i, 0, M) {
      int u, v; cin >> u >> v;
      G[u].push_back(v);
      G[v].push_back(u);
    }

    for (int i = 1; i < N + 1; ++i) {
      sort(G[i].begin(), G[i].end());
    }

    visited1.assign(N + 1, false);
    visited1[X] = true;
    path.clear();
    solve(G, X, Y);
  }

  return 0;
}
