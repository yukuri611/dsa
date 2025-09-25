#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N; cin >> N;
  vector<int> P(N), A(N), B(N);
  for (int i = 0; i < N; ++i) cin >> P[i] >> A[i] >> B[i];
  
  vector<int> sumB(N + 1,0);
  for (int i = 1; i <= N; ++i) {
    sumB[i] += sumB[i - 1] + B[i - 1];
  }

  vector<vector<int>> memo(N + 1, vector<int>(1001));
  for (int j = 0; j < 1001; ++j) {
    memo[N][j] = j;
  }
  for (int i = N - 1; i > -1; --i) {
    for (int j = 0; j < 1001; ++j) {
      if (j > P[i]) {
        //テンションがB下がる
        int new_tension = max(0, j - B[i]);
        memo[i][j] = memo[i + 1][new_tension];
      }
      else {
        int new_tension = j + A[i];
        memo[i][j] = memo[i + 1][new_tension];
      } 
    }
  }

  int Q; cin >> Q;
  for (int _ = 0; _ < Q; ++_) {
    int x; cin >> x;
    auto it = lower_bound(sumB.begin(), sumB.end(), x - 1000);
    if (it == sumB.end()) {
      //最後まで1001以上
      cout << x - sumB.back() << endl;
    }
    else {
      int curr_i = it - sumB.begin();
      int curr_tension = x - *it;
      cout << memo[curr_i][curr_tension] << endl; 
    }
  }

  return 0;
}
