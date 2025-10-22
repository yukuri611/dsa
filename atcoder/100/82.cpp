#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

ll mod = 1e9 + 7;

ll powermod(ll a, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) {
            res *= a;
            res %= mod;
        }
        a *= a;
        a %= mod;
        n >>= 1;
    }
    return res;
}

ll inverse(ll n) { return powermod(n, mod - 2); }

ll sum(ll a, ll b) {
    ll modA = a % mod;
    ll modB = b % mod;
    ll diff = (modB - modA + 1 + mod) % mod;
    ll res = (modA + modB) * diff;
    res %= mod;
    res *= inverse(2);
    res %= mod;
    return res;
}

ll solve(ll l, ll r) {
    ll sz_l = to_string(l).size();
    ll sz_r = to_string(r).size();

    if (sz_l == sz_r) {
        ll res = sum(l, r) * sz_l;
        res %= mod;
        return res;
    }

    ll curr = 1;
    rep(i, sz_l) { curr *= 10; }

    ll res = 0;
    res += sum(l, curr - 1) * sz_l;
    for (int i = sz_l + 1; i < sz_r; ++i) {
        res += sum(curr, curr * 10 - 1) * i;
        curr *= 10;
    }
    res += sum(curr, r) * sz_r;
    res %= mod;

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll L, R;
    cin >> L >> R;
    ll res = solve(L, R);
    cout << res << endl;
    return 0;
}
