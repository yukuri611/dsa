#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int main() {
  int N, M; cin >> N >> M;
  vector<vector<ll>> G(N, vector<ll>(N, LLONG_MAX));
  for (int i = 0; i < N; ++i) G[i][i] = 0;
  for (int i = 0; i < M; ++i) {
    ll a, b, c; cin >> a >> b >> c;
    --a; --b;
    G[a][b] = min(c, G[a][b]);
    G[b][a] = min(c, G[b][a]);
  }

  int K, T; cin >> K >> T;
  vector<bool> Airport(N + 1, false);
  for (int i = 0; i < K; ++i) {
    int d; cin >> d;
    --d;
    Airport[d] = true;
  }

  vector<vector<ll>> dist(N + 1, vector<ll>(N + 1, LLONG_MAX));
  //初期化
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (Airport[i] && Airport[j]) {
        dist[i][j] = T;
      }
      if (G[i][j] != LLONG_MAX) {
        dist[i][j] = min(dist[i][j], G[i][j]);
      }
    }
  }

  for (int k = 0; k < N; ++k) {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (dist[i][k] != LLONG_MAX && dist[k][j] != LLONG_MAX) {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
  }
  ll total_sum = 0;

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (dist[i][j] != LLONG_MAX) total_sum += dist[i][j];
    }
  }

  int Q; cin >> Q;
  for (int _ = 0; _ < Q; ++_) {
    int f; cin >> f;
    if (f == 1) {
      int x, y, t; cin >> x >> y >> t;
      x--; y--;
      if (t < G[x][y]) {
        G[x][y] = t;
        for (int i = 0; i < N; ++i) {
          for (int j = 0; j < N; ++j) {
            ll new_dist = min(dist[i][x] + dist[y][j], dist[i][y] + dist[x][j]) + G[x][y];
            if (new_dist < dist[i][j]) {
              total_sum -= (dist[i][j] - new_dist);
              dist[i][j] = new_dist;
            }
          }
        }
      }
    }
    else if (f == 2) {
      int x; cin >> x;
      --x;
      Airport[x] = true;
      for (int y = 0; y < N; ++y) {
        if (Airport[y]) {
          for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
              ll new_dist = min(dist[i][x] + dist[y][j], dist[i][y] + dist[x][j]) + T;
              if (new_dist < dist[i][j]) {
                total_sum -= (dist[i][j] - new_dist);
                dist[i][j] = new_dist;
              }
            }
          }
        }
      }
    }
    else {
      cout << total_sum << endl;
    }
  }

  return 0;

}
