#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  int N, M; cin >> N >> M;
  vector<vector<ll>> A(N, vector<ll>(M));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> A[i][j];
    }
  }

  ll res = 0;
  for (int t1 = 0; t1 < M; ++t1) {
    for (int t2 = t1 + 1; t2 < M; ++t2) {
      ll curr_sum = 0;
      for (int i = 0; i < N; ++i) {
        curr_sum += max(A[i][t1], A[i][t2]);
      }
      res = max(res, curr_sum);
    }
  }

  cout << res << endl;
  return 0;

  
}
