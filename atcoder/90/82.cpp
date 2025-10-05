#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

ll mod = 1e9 + 7;

ll power(ll a, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res *= a;
        res %= mod;
        a *= a;
        a %= mod;
        n >>= 1;
    }
    return res;
}
ll inverse(ll n) { return power(n, mod - 2); }

ll f(ll x) {
    ll v1 = x % mod;
    ll v2 = (x + 1) % mod;
    ll v = (v1 * v2) % mod;
    return (v * inverse(2)) % mod;
}

ll solve(ll n) {
    if (n == 0) return 0;
    string s = to_string(n);
    int len = s.size();
    ll res = 0;
    ll ten_power = 1;
    for (int d = 1; d < len; ++d) {
        ll a = ten_power;
        ll b = ten_power * 10 - 1;
        ll sum = (f(b) - f(a - 1) + mod) % mod;
        res = (res + (ll)d * sum) % mod;
        ten_power *= 10;
    }
    ll a = ten_power;
    ll b = n;
    ll sum = (f(b) - f(a - 1) + mod) % mod;
    res = (res + (ll)len * sum) % mod;
    return res;
}

int main() {
    ll L, R;
    cin >> L >> R;

    ll cL = solve(L - 1);
    ll cR = solve(R);
    cout << (cR - cL + mod) % mod << endl;
    return 0;
}
