#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

ll mod = 1e9 + 7;

ll power(ll a, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}

int findDigit(ll n) {
    int res = 0;
    while (n > 0) {
        n /= 10;
        res++;
    }
    return res;
}

ll powerMod(ll a, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        n >>= 1;
    }
    return res;
}

ll inverse(ll a) { return powerMod(a, mod - 2); }

ll calcSum(ll l, ll r) {
    l %= mod;
    r %= mod;
    ll res = (l + r) % mod;
    res = (res * (r - l + 1)) % mod;
    res = (res * inverse(2)) % mod;
    return res;
}

ll solve(ll n) {
    int digit = findDigit(n);

    ll res = 0;
    for (int i = 1; i < digit; ++i) {
        // ll r, l;
        // l = 1;
        // rep(j, i - 1) { l *= 10; }
        // r = l * 10 - 1;
        ll r = power(10, i) - 1;
        ll l = power(10, i - 1);
        ll sum = calcSum(l, r);
        ll cnt = (sum * i) % mod;
        res = (res + cnt) % mod;
    }
    ll r = n;
    // ll l = 1;
    // rep(j, digit - 1) { l *= 10; }
    ll l = power(10, digit - 1);
    ll sum = calcSum(l, r);
    ll cnt = (sum * digit) % mod;
    res = (res + cnt) % mod;

    return res;
}

int main() {
    ll L, R;
    cin >> L >> R;
    ll cntR = solve(R);
    ll cntL = solve(L - 1);

    ll res = (cntR - cntL + mod) % mod;
    cout << res << endl;
    return 0;
}
