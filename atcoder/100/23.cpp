#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int main() {
  int N, M; cin >> N >> M;
  vector<ll> P(N + 1);
  for (int i = 0; i < N; ++i) {
    cin >> P[i];
  }
  P[N] = 0;

  vector<ll> P2;
  for (int i = 0; i < N + 1; i++) {
    for (int j = i; j < N + 1; ++j) {
      P2.push_back(P[i] + P[j]);
    }
  }
  sort(P2.begin(), P2.end());

  ll res = 0;
  for (int i = 0; i < P2.size(); ++i) {
    auto it = upper_bound(P2.begin(), P2.end(), M - P2[i]);
    if (it != P2.begin()) res = max(res, P2[i] + *(it - 1)); 
  }
  cout << res << endl;
  return 0;
}
