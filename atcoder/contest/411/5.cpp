#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)
ll mod = 998244353;

ll modpow(ll base, ll exp) {
    ll res = 1;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

ll inverse(ll n) { return modpow(n, mod - 2); }

int main() {
    // 入力
    int N;
    cin >> N;
    int m = 6;
    vector<vector<int>> A(N, vector<int>(m));
    rep(i, N) {
        rep(j, m) { cin >> A[i][j]; }
    }

    // 全ての出目を小さい順にソート
    vector<int> xs;
    rep(i, N) rep(j, m) xs.push_back(A[i][j]);
    sort(xs.begin(), xs.end());

    ll res = 0;
    ll inv_m_pow_N = inverse(modpow(m, N));
    int xprev = 0;
    for (int x : xs) {
        ll p = 1;
        rep(i, N) {
            int cnt = 0;
            rep(j, m) {
                if (A[i][j] < x) cnt++;
            }
            p = (p * cnt) % mod;
        }
        p = (p * inv_m_pow_N) % mod;
        res = (res + (((1 - p) + mod) % mod) * (x - xprev)) % mod;
        xprev = x;
    }

    cout << res << endl;
    return 0;
}
