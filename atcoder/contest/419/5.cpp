#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, M, L; cin >> N >> M >> L;
  vector<int>A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }

  vector<vector<int>> f(L, vector<int>(M)); // f[i][j] = A[i], A[i+L], ...をすべてあまりjにするのに必要な最小操作数
  for (int i = 0; i < L; ++i) {
    for (int j = 0; j < M; ++j) {
      int cost = 0;
      for (int k = 0; i + L * k < N; ++k) {
        int remain = A[i + L * k];
        if (remain <= j) {
          cost += j - remain;
        } 
        else {
          cost += M - remain + j;
        }
      }
      f[i][j] = cost;
    }
  }

  vector<int> dp = f[0]; //dp[i][j] = A[0] ~ A[i], A[L] ~ A[L + i]... の和がそれぞれあまりjになるための最小操作回数
  for (int i = 1; i < L; ++i) {
    vector<int> nextDp(M, INT_MAX);
    for (int j = 0; j < M; ++j) {
      for (int k = 0; k < M; ++k) {
        // (j - k) が負になる可能性を考慮する
        int prev_j = (j - k + M) % M; 
        nextDp[j] = min(nextDp[j], dp[prev_j] + f[i][k]);
      }
    }
    dp = nextDp;
  }

  cout << dp[0] << endl;
  return 0;

}
