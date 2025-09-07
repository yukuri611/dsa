#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, M; cin >> N >> M;
  vector<int> T(N);
  for (int i = 0; i < N; ++i) {
    int doll; cin >> doll;
    --doll;
    T[i] = doll;
  }

  vector<vector<int>> count(M, vector<int>(N + 1, 0)); //count[doll][i] = 0~i-1までに存在するdollの個数
  for (int i = 1; i <= N; ++i) {
    for (int doll = 0; doll < M; ++doll) {
      if (T[i-1] == doll) count[doll][i] = count[doll][i-1] + 1;
      else count[doll][i] = count[doll][i - 1];
    }
  }
  vector<int> len((1 << M), 0); //len[S] = 集合Sの長さ
  for (int s = 1; s < (1 << M); ++s) {
    for (int doll = 0; doll < M; ++doll) {
      if ((s & (1 << doll)) == 0) continue;
      len[s] += count[doll][N];
    }
  }

  vector<int> dp((1 << M), INT_MAX); //dp[S] = Sを並べるときに必要な最小取り除き数。
  dp[0] = 0;
  for (int S = 0; S < (1 << M); ++S) {
    for (int newDoll = 0; newDoll < M; ++newDoll) {
      if ((S & (1 << newDoll))) continue; //すでにnewdollが含まれる。
      int nextS = S | (1 << newDoll); 
      int remove_count = dp[S] + count[newDoll][N] - (count[newDoll][len[nextS]] - count[newDoll][len[S]]);
      dp[nextS] = min(dp[nextS], remove_count);
    }
  }

  cout << dp[(1 << M) - 1] << endl;
  return 0;
}
