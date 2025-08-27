#include <iostream>
#include <vector> 
#include <climits>

using namespace std;

int main() {
  int N, M, X; cin >> N >> M >> X;
  vector<int> cost(N);
  vector<vector<int>> A(N, vector<int>(M));
  for (int i = 0; i < N; i++) {
    cin >> cost[i];
    for (int j = 0; j < M; j++) {
      cin >> A[i][j];
    }
  }

  bool hasAnswer = false;
  int res = INT_MAX;
  for (int i = 0; i < (1 << N); i++) { 
    vector<int> understand_level(M);
    int total_cost = 0;
    for (int j = 0; j < N; j++) {
      if (i & (1 << j)) {
        total_cost += cost[j];
        for (int k = 0; k < M; k++) {
          understand_level[k] += A[j][k];
        }
      }
    }
    bool valid = true;
    for (int j = 0; j < M && valid; j++) {
      if (understand_level[j] < X) valid = false;
    }
    if (valid) {
      hasAnswer = true;
      res = min(res, total_cost);
    }
  }

  if (hasAnswer) cout << res << endl;
  else cout << -1 << endl;
  return 0;
}
