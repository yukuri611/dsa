#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, M; cin >> N >> M;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    int doll; cin >> doll;
    A[i] = doll - 1;
  }
  vector<vector<int>> count(M, vector<int>(N + 1,0)); //count[i][j] = 人形iのインデックスj-1までにある個数
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      count[j][i + 1] = count[j][i];
    }
    count[A[i]][i + 1]++;
  }

  vector<int> pos((1 << M), 0);  //pos[mask] = maskに含まれる人形の総数
  for (int mask = 0; mask < (1 << M); ++mask) {
    for (int i = 0; i < M; ++i) {
      if (mask & (1 << i)) {
        pos[mask] += count[i][N];
      }
    }
  }
  
  vector<int> dp((1 << M), 0);
  for (int mask = 0; mask < (1 << M); ++mask) {
    for (int new_doll = 0; new_doll < M; ++new_doll) {
      if (mask & (1 << new_doll)) continue; //すでに並べてある。
      int next_mask = mask | (1 << new_doll);
      int start_pos = pos[mask];
      int end_pos = pos[next_mask];
      int kept_dolls = count[new_doll][end_pos] - count[new_doll][start_pos];
      dp[next_mask] = max(dp[next_mask], dp[mask] + kept_dolls);
    }
  }

  cout << N - dp[(1 << M) - 1] << endl;
  return 0;
}
