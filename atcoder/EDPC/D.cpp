#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template<class T> inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  int N, maxW; cin >> N >> maxW;
  vector<ll> W(N), V(N);
  for (ll i = 0; i < N; ++i) {
    cin >> W[i] >> V[i];
  }

  vector<ll> dp(maxW + 1, -1);
  dp[0] = 0;
  ll res = 0;
  for (int i = 0; i < N; ++i) {
    vector<ll> nextDp = dp;
    for (int w = 0; w <= maxW; ++w) {
      if (dp[w] == -1) continue;
      int nw = w + W[i];
      if (nw <= maxW) {
        ll nv = dp[w] + V[i];
        chmax(nextDp[nw], nv); 
        chmax(res, nv);
      }
    }
    dp = nextDp;
  }
  cout << dp[maxW] << endl;
  return 0;
  
}
