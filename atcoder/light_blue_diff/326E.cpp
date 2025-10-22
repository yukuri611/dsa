#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

ll mod = 998244353;

ll power(ll a, ll n) {
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

ll inverse(ll n) { return power(n, mod - 2); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    ll inverseN = inverse(N);
    ll p = inverseN;
    ll res = 0;
    rep(i, N) {
        res += A[i] * p;
        res %= mod;
        p += inverseN * p;
        p %= mod;
    }
    cout << res << endl;
    return 0;
}
