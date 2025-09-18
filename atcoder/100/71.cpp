#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll mod = 1e9 + 7;

ll power(ll a, ll n) {
  ll res = 1;
  while(n > 0) {
    if (n & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    n >>= 1;
  }
  return res;
}

int main() {
  int N, Q; cin >> N >> Q;
  vector<ll> A(N + 1);
  for (int i = 1; i <= N; ++i) cin >> A[i];
  vector<ll> C(Q + 2);
  C[0] = 1; C[Q + 1] = 1;
  for (int i = 1; i <= Q; ++i) cin >> C[i];

  vector<ll> Count(N + 1,0); //Count[i] = 道路iの使用回数
  for (int i = 1; i < Q + 2; ++i) {
    ll s = min(C[i-1], C[i]);
    ll e = max(C[i-1], C[i]);
    Count[s + 1] += 1;
    Count[e + 1] -= 1;
  }
  //累積和を取る。
  for (int i = 3; i <= N; ++i) {
    Count[i] += Count[i - 1];
  }

  ll res = 0;
  for (int i = 2; i <= N; ++i) {
    res = (res + Count[i] * power(A[i-1], A[i])) % mod;
  }

  cout << res << endl;
  return 0;
}
