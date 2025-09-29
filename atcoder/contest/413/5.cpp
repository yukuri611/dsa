#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

void solve() {
  int n; cin >> n;
  int n2 = 1 << n;
  vector<int> P(n2);
  for (int i = 0; i < n2; ++i) cin >> P[i];

  for (int w = 1; w < n2; w <<= 1) {
    for (int l = 0; l < n2; l += w * 2) {
      int r = l + w;
      if (P[l] > P[r]) {
        rep(i, w) {
          swap(P[l + i], P[r + i]);
        }
      }
    }
  }

  for (int p: P) cout << p << " ";
  cout << endl;
}

int main() {
  int T; cin >> T;
  rep(ti, T) {
    solve();
  }
  return 0;
}
