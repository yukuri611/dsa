#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

ll mod = 998244353;

ll powerMod(ll a, ll n) {
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

ll inverseMod(ll n) { return powerMod(n, mod - 2); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll N, X;
    cin >> N >> X;
    vector<ll> T(N);
    rep(i, N) cin >> T[i];

    ll inverseN = inverseMod(N);

    vector<ll> dp(X + 1, 0);
    dp[0] = 1;
    rep(i, X + 1) {
        rep(j, N) {
            if (i + T[j] < X + 1) {
                dp[i + T[j]] += (dp[i] * inverseN) % mod;
                dp[i + T[j]] %= mod;
            }
        }
    }

    ll res = 0;
    for (int i = max(0LL, X + 1 - T[0]); i < X + 1; ++i) {
        res += dp[i];
        res %= mod;
    }
    res *= inverseN;
    res %= mod;

    cout << res << endl;
    return 0;
}
