#include <bits/stdc++.h>

using namespace std;

int dijkstra(vector<vector<int>> G, vector<int> C) {
  int N = G.size() - 1;
  vector<int> min_cost(N + 1, INT_MAX);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, 1});
  while (!pq.empty()) {
    int curr_cost = pq.top().first;
    int curr_node = pq.top().second;
    pq.pop();
    if (curr_node == N) return curr_cost;
    if (curr_cost > min_cost[curr_node]) continue;

    for (int next_node: G[curr_node]) {
      int next_cost = curr_cost + C[curr_node];
      if (min_cost[next_node] > next_cost) {
        min_cost[next_node] = next_cost;
        pq.push({next_cost, next_node});
      }
    }
  }
  return -1;
}
int main() {
  int N, K; cin >> N >> K;
  vector<int> C(N + 1), R(N + 1);
  for (int i = 1; i <= N; ++i) cin >> C[i] >> R[i];
  vector<vector<int>> G(N + 1);
  for (int i = 0; i < K; ++i) {
    int a, b; cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vector<vector<int>> G2(N + 1);
  for (int i = 1; i <= N; ++i) {
    vector<int> distance(N+1,-1);
    distance[i] = 0;
    queue<int> q;
    q.push(i);
    while(!q.empty()) {
      int curr_node = q.front();
      q.pop();
      if (distance[curr_node] == R[i]) continue;
      for (int next_node: G[curr_node]) {
        if (distance[next_node] != -1) continue;
        distance[next_node] = distance[curr_node] + 1;
        q.push(next_node);
      }
    }
    for (int j = 1; j <= N; ++j) {
      if (distance[j] != -1) G2[i].push_back(j);
    }
  }

  int res = dijkstra(G2, C);
  cout << res << endl;
  return 0;
}
