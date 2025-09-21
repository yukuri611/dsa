#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  int N; cin >> N;
  vector<ll> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }

  ll res = 0;
  for (int n = 0; n < N - 1; ++n) {
    int min_s = 0;
    for (int i = 0; i < N - (n + 1); ++i) {
      if (A[min_s] + A[min_s + 1] > A[i] + A[i + 1]) min_s = i;
    }
    A[min_s] = A[min_s] + A[min_s + 1];
    for (int i = min_s + 1; i < N - 1; ++i) {
      A[i] = A[i + 1];
    }
    A.resize(N - (n + 1));
    res += A[min_s];
  }

  cout << res << endl;
  return 0;
}
