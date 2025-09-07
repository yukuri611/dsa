#include <bits/stdc++.h>

using namespace std;
using LL = long long;
int main() {
  int N; cin >> N;
  vector<vector<LL>> A(N+1, vector<LL>(N+1));
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      cin >> A[i][j];
    }
  }

  bool valid = true;
  for (int k = 1; k <= N; ++k) {
    for (int i = 1; i <= N; ++i) {
      for (int j = 1; j <= N; ++j) {
        if (A[i][j] > A[i][k] + A[k][j]) {
          cout << -1 << endl;
          return 0;
        }
      }
    }
  }

  LL res=0;
  for (int i = 1; i <= N; ++i) {
    for (int j = i+1; j <= N; ++j) {
      bool need = true;
      for (int k = 1; k <= N; ++k) {
        if (k == i || k == j) continue;
        if (A[i][k] + A[k][j] == A[i][j]) {
          need = false;
          break;
        } 
      }
      if (need) res += A[i][j];
    }
  }

  cout << res << endl;
  return 0;
}
