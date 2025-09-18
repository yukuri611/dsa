#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll mod = 1e9 + 7;

ll factorial(ll n) {
  ll res = 1;
  for (int i = 2; i <= n; ++i) {
    res = (res * i) % mod;
  }
  return res;
}

ll power(ll a, ll n) {
  ll res = 1;
  while(n > 0) {
    if (n & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    n >>= 1;
  }
  return res;
}

ll inverse(ll a) {
  return power(a, mod - 2);
}

ll combination(ll n, ll k) {
  ll a = factorial(n);
  ll b = factorial(n-k);
  ll c = factorial(k);
  return (a * inverse((b * c) % mod)) % mod;
} 

int main() {
  ll W, H; cin >> W >> H;
  cout << combination(W + H - 2, W - 1) << endl;
  return 0;
}
