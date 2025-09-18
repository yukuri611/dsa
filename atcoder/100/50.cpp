#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  #define int ll
  int N, M; cin >> N >> M;
  vector<vector<pair<ll, ll>>> G(N, vector<pair<ll, ll>>(N, {-1,-1}));
  for (int i = 0; i < M; ++i) {
    ll s, t, d, time; cin >> s >> t >> d >> time;
    --s; --t;
    G[s][t] = {d,time};
    G[t][s] = {d,time};
  }
  
  vector<vector<pair<ll, ll>>> dp((1 << N), vector<pair<ll, ll>>(N, {LLONG_MAX, -1})); //dp[S] = 集合S, 現在地vの時の最小移動距離, 行き方の総数
  dp[1][0] = {0,1};
  for (ll S = 1; S < (1 << N); ++S) {
    for (int i = 0; i < N; ++i) {
      if (!((S >> i) & 1)) {
        //iはまだ訪れていない
        ll nextS = S | (1 << i);
        for (int j = 0; j < N; ++j) {
          //最後に訪れたところをjとする。
          if (dp[S][j].second == -1) continue; //jが現在地であることはない
          if (G[j][i].first == -1) continue; //道がない
          ll total_dist = dp[S][j].first + G[j][i].first;
          if (total_dist > G[j][i].second) continue; //時間切れで通れない
          if (total_dist > dp[nextS][i].first) continue; //最短経路ではない
          if (total_dist == dp[nextS][i].first) {
            dp[nextS][i].second += dp[S][j].second;
          } 
          else {
            dp[nextS][i] = {total_dist, dp[S][j].second};
          }
        }
      }
    }
  }

  ll res = LLONG_MAX;
  ll count = -1;
  ll mask = (1 << N) - 1;
  for (int i = 0; i < N; ++i) {
    if (dp[mask][i].second == -1) continue;
    if (G[i][0].first == -1) continue; //道がない;
    ll total_dist = dp[mask][i].first + G[i][0].first;
    if (total_dist > G[i][0].second) continue; //時間切れで通れない
    if (total_dist > res) continue; //最短経路ではない
    if (total_dist == res) {
      count += dp[mask][i].second;
    } 
    else {
      res = total_dist;
      count = dp[mask][i].second;
    }
  } 

  if (res == LLONG_MAX) cout << "IMPOSSIBLE" << endl;
  else cout << res << " " << count <<  endl;
  return 0;
}
