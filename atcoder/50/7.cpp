#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, M; cin >> N >> M;
  vector<vector<bool>> adj(N, vector<bool>(N, false));
  for (int i = 0; i < M; ++i) {
    int u, v; cin >> u >> v;
    --u; --v;
    adj[u][v] = adj[v][u] = true;
  }

  int N1 = N/2;
  int N2 = N - N1;

  //後半グループの集合が独立かどうかを計算する。
  vector<int> dp2(1 << N2, 0); //dp2[S] = 集合Sの部分集合で最大の独立集合の大きさ
  //初めに書く集合Sについて、Sが独立かどうかチェック。独立ならdpに、そのサイズを記録
  for (int mask = 1; mask < (1 << N2); ++mask) {
    int p_i = __builtin_ctz(mask); //1の位から0が何個並んでいるか＝最初に1が出てくるインデックス。
    int p_node = N1 + p_i;
    bool possible = true;
    for (int i = 0; i < N2; ++i) {
      if ((mask >> i) & 1) {
        if (adj[p_node][N1 + i]) {
          possible = false;
          break;
        }
      }
    }
    if (possible) dp2[mask] = dp2[mask & ~(1 << p_i)] + 1;
  } 
  //部分集合をおおもとの集合に伝播させていき、dp2が、独立な部分集合の最大サイズを持つようにする。
  for (int i = 0; i < N2; ++i) {
    for (int mask = 0; mask < (1 << N2); ++mask) {
      if ((mask >> i) & 1) {
        dp2[mask] = max(dp2[mask], dp2[mask & ~(1 << i)]);
      }
    }
  }

  int max_ans = 0;

  for (int mask1 = 0; mask1 < (1 << N1); ++mask1) {
    //集合mask1が独立集合かどうかチェック
    bool isIndependent1 = true;
    int size1 = 0;
    for (int i = 0; isIndependent1 && i < N1; ++i) {
      if (!((mask1 >> i) & 1)) continue;
      size1++;
      for (int j = i + 1; j < N1; ++j) {
        if (!((mask1 >> j) & 1)) continue;
        if (adj[i][j]) {
          isIndependent1 = false;
          break;
        }
      }
    }
    if(!isIndependent1) continue;
    
    //独立集合mask1の要素と独立なV2の要素を洗い出す。
    int forbidden_mask2 = 0;
    for (int i = 0; i < N1; ++i) {
      if ((mask1 >> i) & 1) {
        for (int j = 0; j < N2; ++j) {
          if (adj[i][N1 + j]) {
            forbidden_mask2 |= (1 << j);
          }
        }
      }
    }

    //mask1の全要素と独立なV2の集合の最大の大きさを求める
    int allowed_mask2 = ((1 << N2) - 1) & ~forbidden_mask2;
    int size2 = dp2[allowed_mask2];
    max_ans = max(max_ans, size1 + size2);
  }

  cout << max_ans << endl;
  return 0;
}
