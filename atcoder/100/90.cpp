#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, M; cin >> N >> M;
  vector<int> X(N + M), Y(N + M);
  vector<double> R(N + M, 1000);
  for (int i = 0; i < N; ++i) cin >> X[i] >> Y[i] >> R[i];
  for (int i = 0; i < M; ++i) cin >> X[N + i] >> Y[N + i];


  for (int i = 0; i < M; ++i) {
    int x = X[N + i]; int y = Y[N + i];
    for (int j = 0; j < N; ++j) {
      double distance = sqrt((X[j] - x) * (X[j] - x) + (Y[j] - y) * (Y[j] - y));
      if (R[N+i] > distance - R[j]) R[N + i] = distance - R[j];
    }
  }
  for (int i = 0; i < M; ++i) {
    int x = X[N + i]; int y = Y[N + i];
    for (int j = N; j < N + M; ++j) {
      if (N + i == j) continue;
      double distance = sqrt((X[j] - x) * (X[j] - x) + (Y[j] - y) * (Y[j] - y));
      if (R[N + i] > distance / 2) R[N + i] = distance/2;
    }
  }
  double res = R[0];
  for (int i = 0; i < N + M; ++i) {
    res = min(res, R[i]);
  }

  cout << fixed << setprecision(7) << res << endl;
  return 0;
}

