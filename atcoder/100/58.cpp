#include <bits/stdc++.h>

using namespace std;
using LL = long long;

LL djkstra(vector<vector<int>> &adj, set<int> zombie, set<int> &dangerous, int P, int Q) {
  int n = adj.size() - 1;
  vector<LL> Cost(n + 1, LLONG_MAX);
  Cost[1] = 0;
  priority_queue<pair<LL, int>, vector<pair<LL, int>>, greater<pair<LL,int>>> pq;
  pq.push({0,1});
  while (!pq.empty()) {
    LL curr_cost = pq.top().first;
    int u = pq.top().second;
    pq.pop();
    if (u == n) {
      if (dangerous.count(n)) return curr_cost - Q;
      else return curr_cost - P;
    }
    if (curr_cost > Cost[u]) continue;
    for (int v: adj[u]) {
      if (zombie.count(v)) continue;
      LL new_cost = (dangerous.count(v)) ? curr_cost + Q: curr_cost + P;
      if (new_cost < Cost[v]) {
        Cost[v] = new_cost;
        pq.push({new_cost, v});
      }
    }
  }
  return -1;
}

int main() {
  int N, M, K, S; cin >> N >> M >> K >> S;
  int P, Q; cin >> P >> Q;
  set<int> zombie;
  for (int i = 0; i < K; ++i) {
    int c; cin >> c;
    zombie.insert(c);
  }
  vector<vector<int>> adj(N + 1);
  for (int i = 0; i < M; ++i) {
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

set<int> dangerous;
vector<int> dist(N + 1, -1); // ゾンビからの最短距離を管理 (-1は未訪問)
queue<int> q;

// 全てのゾンビの町を始点としてキューに入れる
for (int z : zombie) {
    if (dist[z] == -1) {
      q.push(z);
      dist[z] = 0;
    }
}

// マルチソースBFS
while (!q.empty()) {
    int u = q.front();
    q.pop();

    dangerous.insert(u); // ゾンビからS以下の距離にある町は危険

    if (dist[u] == S) continue; // S本より遠くは探索しない

    for (int v : adj[u]) {
      if (dist[v] == -1) { // まだ訪れていない町なら
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }

  LL res = djkstra(adj, zombie, dangerous, P, Q);
  cout << res << endl;
  return 0;
}
