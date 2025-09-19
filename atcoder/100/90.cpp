#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, M; cin >> N >> M;
  vector<int> X(N + M), Y(N + M), R(N);
  for (int i = 0; i < N; ++i) {
    cin >> X[i] >> Y[i] >> R[i];
  }
  for (int i = N; i < N + M; ++i) {
    cin >> X[i] >> Y[i];
  }

  double l = 0; double r = 300;
  while (r - l > pow(10,-6)) {
    double mid = (r - l) / 2 + l;
    bool valid = true;
    for (int i = 0; i < N + M; ++i) {
      for (int j = i + 1; j < N + M; ++j) {
        if (i < N && j < N) {
          if (R[i] < mid || R[j] < mid) {
            valid = false;
            break;
          }
        }
        if (i < N && j >= N) {
          double dist = sqrt(pow(X[i] - X[j], 2) + pow(Y[i] - Y[j], 2));
          if (dist - R[i] < mid) {
            valid = false;
            break;
          }
        }
        else {
          double dist = sqrt(pow(X[i] - X[j], 2) + pow(Y[i] - Y[j], 2));
          if (dist / 2 < mid) {
            valid = false;
            break;
          }
        }
      }
    }
    if (valid) l = mid;
    else r = mid;
  }

  cout << fixed << setprecision(6) << l << endl;
  return 0;
}
