#include <bits/stdc++.h>

using namespace std;
using LL = long long;
int main() {
  int V, E; cin >> V >> E;
  vector<vector<LL>> dist(V, vector<LL>(V, LLONG_MAX));
  for (int i = 0; i < E; ++i) {
    int s, t, d; cin >> s >> t >> d;
    dist[s][t] = d;
  }
  for (int i = 0; i < V; ++i) dist[i][i] = 0;

  for (int k = 0; k < V; ++k) {
    for (int i = 0; i < V; ++i) {
      for (int j = 0; j < V; ++j) {
        if (dist[i][k] == LLONG_MAX || dist[k][j] == LLONG_MAX) continue;
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  for (int i = 0; i < V; ++i) {
    if (dist[i][i] < 0) {
      cout << "NEGATIVE CYCLE" << endl;
      return 0;
    }
  }

  for (int i = 0; i < V; ++i) {
    for (int j = 0; j < V-1; ++j) {
      if (dist[i][j] == LLONG_MAX) cout << "INF" << " ";
      else cout << dist[i][j] << " ";
    }
    if (dist[i][V-1] == LLONG_MAX) cout << "INF" << endl;
    else cout << dist[i][V-1] << endl; 
  }
  return 0;
}
