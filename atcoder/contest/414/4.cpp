#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  int N, M; cin >> N >> M;
  vector<ll> X(N);
  for (int i = 0; i < N; ++i) cin >> X[i];
  sort(X.begin(), X.end());
  vector<ll> diff(N - 1);
  for (int i = 0; i < N - 1; ++i) {
    diff[i] = X[i + 1] - X[i];
  }

  sort(diff.begin(), diff.end());
  ll res = 0;
  for (int i = 0; i < N - 1 - (M - 1); ++i) {
    res += diff[i];
  }

  cout << res << endl;
  return 0;
}
