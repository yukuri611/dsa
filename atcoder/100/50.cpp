#include <bits/stdc++.h>

using namespace std;
const long long INF = LLONG_MAX / 2;

int main() {
  int N, M; cin >> N >> M;
  vector<vector<pair<long long, long long>>> g(N, vector<pair<long long, long long>>(N, {-1,-1}));
  if (N == 1) {
    cout << "0 1" << endl;
    return 0;
  }
  for (int i = 0; i < M; ++i) {
    int s, t, d, time; cin >> s >> t >> d >> time;
    g[s - 1][t - 1] = {d, time};
    g[t - 1][s - 1] = {d, time};
  }

  vector<vector<pair<long long, long long>>> dp((1 << N), vector<pair<long long, long long>>(N, {INF,0})); 
  dp[(1 << 0)][0] = {0,1};
  for (int s = 1; s < (1 << N); ++s) {
    for (int v = 0; v < N; ++v) {
      if (dp[s][v].first == INF) continue; 
      for (int u = 0; u < N; ++u) {
        if ((s & (1 << u)) != 0) continue; //訪問済み
        if (g[v][u].first == -1) continue; //vからuには行けない
        int nextS = s | (1 << u);
        long long dist = dp[s][v].first + g[v][u].first;
        if (dist > g[v][u].second) continue; //時間切れ
        if (dp[nextS][u].first > dist) dp[nextS][u] = {dist, dp[s][v].second};
        else if (dp[nextS][u].first == dist) dp[nextS][u].second += dp[s][v].second;
      }
    }
  }
  pair<long long, long long> res = {INF, INF};
  for (int v = 0; v < N; ++v) {
    long long d, time; d = g[v][0].first; time = g[v][0].second;
    if (d == -1) continue;
    if (dp[(1 << N) - 1][v].first == INF) continue;
    long long temp = dp[(1 << N) - 1][v].first + d;
    long long count = dp[(1 << N) - 1][v].second;
    if (temp > time) continue;
    if (res.first == temp) res.second += count;
    else if (res.first > temp) res = {temp, count};
  }

  if (res.first == INF) cout << "IMPOSSIBLE" << endl;
  else cout << res.first << " " << res.second << endl;
  return 0;
}
