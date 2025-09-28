#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N, M;
vector<vector<ll>> G;
vector<vector<ll>> dist;
ll total_sum = 0;

void update(int x, int y) {
  for (int i = 0; i < N + 1; ++i) {
    for (int j = 0; j < N + 1; ++j) {
      ll d1 = LLONG_MAX;
      if (dist[i][x] != LLONG_MAX && dist[y][j] != LLONG_MAX) d1 = dist[i][x] + dist[y][j] + G[x][y];
      ll d2 = LLONG_MAX;
      if (dist[i][y] != LLONG_MAX && dist[x][j] != LLONG_MAX) d2 = dist[i][y] + dist[x][j] + G[y][x];
      ll new_dist = min(d1, d2);
      if (new_dist < dist[i][j]) {
        if (i >= 1 && j >= 1) {
          if (dist[i][j] == LLONG_MAX) {
            total_sum += new_dist;
          }
          else if (new_dist < dist[i][j]) {
            total_sum -= (dist[i][j] - new_dist);
          }
        }
        dist[i][j] = new_dist;
      }
    }
  }
}

int main() {
  cin >> N >> M;
  G.assign(N + 1, vector<ll>(N + 1, LLONG_MAX)); //G(0)を空とする
  for (int i = 0; i < N + 1; ++i) G[i][i] = 0;
  for (int i = 0; i < M; ++i) {
    ll a, b, c; cin >> a >> b >> c;
    G[a][b] = min(c, G[a][b]);
    G[b][a] = min(c, G[b][a]);
  }

  int K, T; cin >> K >> T;
  for (int i = 0; i < K; ++i) {
    int d; cin >> d;
    G[0][d] = T;
    G[d][0] = 0;
  }

  dist.assign(N + 1, vector<ll>(N + 1, LLONG_MAX));
  //初期化
  for (int i = 0; i < N + 1; ++i) {
    for (int j = 0; j < N + 1; ++j) {
      if (G[i][j] != LLONG_MAX) {
        dist[i][j] = G[i][j];
      }
    }
  }
  //ワーシャルフロイド
  for (int k = 0; k < N + 1; ++k) {
    for (int i = 0; i < N + 1; ++i) {
      for (int j = 0; j < N + 1; ++j) {
        if (dist[i][k] != LLONG_MAX && dist[k][j] != LLONG_MAX) {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
  }


  for (int i = 1; i < N + 1; ++i) {
    for (int j = 1; j < N + 1; ++j) {
      if (dist[i][j] != LLONG_MAX) total_sum += dist[i][j];
    }
  }

  int Q; cin >> Q;
  for (int _ = 0; _ < Q; ++_) {
    int f; cin >> f;
    if (f == 1) {
      int x, y, t; cin >> x >> y >> t;
      if (t < G[x][y]) {
        G[x][y] = t;
        G[y][x] = t;
        update(x,y);
      }
    }
    else if (f == 2) {
      int x; cin >> x;
      G[x][0] = 0;
      G[0][x] = T;
      update(x, 0);
    }
    else {
      cout << total_sum << endl;
    }
  }
  return 0;
}
