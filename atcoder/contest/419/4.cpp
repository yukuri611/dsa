#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, M; cin >> N >> M;
  string S, T; cin >> S >> T;
  vector<int> imos(N + 1, 0);
  for (int i = 0; i < M; ++i) {
    int l, r; cin >> l >> r;
    l--; r--;
    imos[l] += 1;
    imos[r + 1] -= 1;
  }
  for (int i = 1; i < N+1; ++i) {
    imos[i] += imos[i - 1];
  }
  string ans;
  for (int i = 0; i < N; ++i) {
    if (imos[i] % 2) {
      ans += T[i];
    }
    else {
      ans += S[i];
    }
  }
  cout << ans << endl;
  return 0;
}
