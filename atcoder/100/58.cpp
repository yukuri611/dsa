#include <bits/stdc++.h>

using namespace std;
using LL = long long;

LL Dijkstra(vector<vector<int>>&G, set<int>& Z, set<int>& D, int P, int Q) {
  int N = G.size();
  int dest = N - 1;
  vector<LL> minimum_cost(N, LLONG_MAX);
  minimum_cost[0] = 0;
  priority_queue<pair<LL, int>, vector<pair<LL, int>>, greater<pair<LL, int>>> pq;
  pq.push({0, 0});
  while(!pq.empty()) {
    LL c = pq.top().first;
    int u = pq.top().second;
    pq.pop();
    if (minimum_cost[u] < c) continue;
    if (u == dest) {
      if (D.count(dest)) return c - Q;
      else return c - P;
    }
    minimum_cost[u] = c;
    for (auto v: G[u]) {
      LL new_cost;
      if (Z.count(v)) continue;
      if (D.count(v)) new_cost = c + Q;
      else new_cost = c + P;
      if (minimum_cost[v] > new_cost) {
        pq.push({new_cost,v});
        minimum_cost[v] = new_cost;
      }
    }
  }
  return -1;
}

int main() {
  int N, M, K, S; cin >> N >> M >> K >> S;
  int P, Q; cin >> P >> Q;
  vector<vector<int>> G(N);
  set<int> Zombie,Danger;
  for (int i = 0; i < K; ++i) {
    int n; cin >> n;
    n--;
    Zombie.insert(n);
  }
  for (int i = 0; i < M; ++i) {
    int a, b; cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  queue<int> q;
  for (int n: Zombie) q.push(n);
  for (int s = 1; s <= S; ++s) {
    int l = q.size();
    for (int i = 0; i < l; ++i) {
      int u = q.front();
      q.pop();
      for (int v: G[u]) {
        if (Danger.count(v) == 0 && Zombie.count(v) == 0) {
          q.push(v);
          Danger.insert(v);
        }
      }
    }
  }

  LL res = Dijkstra(G, Zombie, Danger, P, Q);
  cout << res << endl;
  return 0;
}
