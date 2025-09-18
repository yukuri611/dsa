#include <bits/stdc++.h>

using namespace std;

int main() {
  int N; cin >> N;
  vector<double> X(N), Y(N);
  for (int i = 0; i < N; ++i) cin >> X[i] >> Y[i];

  double res = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      double dist = sqrt(pow(X[i] - X[j], 2) + pow(Y[i] - Y[j], 2));
      res = max(dist, res);
    }
  }

  cout << fixed << setprecision(3) << res << endl;
  return 0;
}
