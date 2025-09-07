#include <bits/stdc++.h>

using namespace std;
using LL = long long;

int main() {
  int N, M; cin >> N >> M;
  if (N == 1) {
    cout << 0 << " " << 1 << endl;
    return 0;
  }
  vector<vector<vector<LL>>> G(N, vector<vector<LL>>(N, vector<LL>(2,-1)));
  for (int _ = 0; _ < M; ++_) {
    int s, t; LL d, time; cin >> s >> t >> d >> time;
    G[s-1][t-1]= {d, time};
    G[t-1][s-1] = {d, time};
  } 

  vector<vector<LL>> dp((1 << N), vector<LL>(N, LLONG_MAX)); //dp[S][i] = 訪問した建物の集合S、現在いる建物iの時における最短移動距離＝かかった時間
  vector<vector<LL>> dp2((1 << N), vector<LL>(N, 0)); //dp2[S][i] = カウント
  dp[1][0] = 0;
  dp2[1][0] = 1;
  for (int S = 1; S < (1 << N); ++S) {
    if ((S & 1) == 0) continue; //店0は最初に訪問済みのはず
    for (int j = 1; j < N; ++j) { // j = 次に訪問する建物
      if (S & (1 << j)) continue; //jは訪問済み
      int nextS = S | (1 << j);
      for (int i = 0; i < N; ++i) { // i = jに移動する前にいる建物
        if ((S & (1 << i)) == 0) continue; //建物iは集合Sにふくまれない。
        if (dp[S][i] == LLONG_MAX) continue;//集合Sに訪問済みの時、現在地がiであることはない。
        if (G[i][j][0] == -1) continue; //iからjに行く道がない
        LL dist = dp[S][i] + G[i][j][0];
        if (G[i][j][1] < dist) continue; //時間切れ

        if (dp[nextS][j] > dist) {
          dp[nextS][j] = dist;
          dp2[nextS][j] = dp2[S][i];
        }
        else if (dp[nextS][j] == dist) {
          dp2[nextS][j] += dp2[S][i];
        }
      }
    }
  }

  LL min_dist, count; min_dist = LLONG_MAX; count = 0;
  for (int j = 1; j < N; ++j) { //jは一番最後に訪問した建物
    if (G[j][0][0] == -1) continue; //jから0に戻る道がない。
    if (dp[(1 << N) - 1][j] == LLONG_MAX) continue; //最後に訪問した建物がjであることはない。
    LL dist = dp[(1 << N) - 1][j] + G[j][0][0];
    if (dist > G[j][0][1]) continue; //時間切れ
    if (min_dist > dist) {
      min_dist = dist;
      count = dp2[(1 << N) - 1][j];
    }
    else if (min_dist == dist) {
      count += dp2[(1 << N) - 1][j];
    }
  }
  if (min_dist == LLONG_MAX) {
    cout << "IMPOSSIBLE" << endl;
  }
  else {
    cout << min_dist << " " << count << endl;
  }
  return 0;
}
