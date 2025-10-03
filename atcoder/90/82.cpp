#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)
ll mod = 1e9 + 7;

ll power(ll a, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) {res *= a; res %= mod;}
        a *= a; a %= mod;
        n >>= 1;
    }
    return res;
}

ll inverse(ll a) {
    return power(a, mod - 2);
}

ll totalsum(ll a, ll b) {
    // aからbまでの和を返す。
    ll term_count = (b - a + 1 + mod) % mod;
    a %= mod;
    b %= mod;
    ll sum_ab = (a + b) % mod;
    return (((sum_ab * term_count) % mod) * inverse(2)) % mod;
}

int main() {
    // 入力
    ll L, R;
    cin >> L >> R;

    // それぞれの桁数を調べる。
    int l = to_string(L).size();
    int r = to_string(R).size();

    ll res = 0;
    if (l == r) {
        res += (totalsum(L, R) * l) % mod;
        cout << res << endl;
        return 0;
    }

    ll start = L;
    ll end = 1;
    rep(i, l) end *= 10;
    end -= 1;
    res += (totalsum(start, end) * l) % mod;
    l++;
    while (l < r) {
        ll start = 1;
        rep(i, l-1) start *= 10;
        ll end =  1;
        rep(i, l) end *= 10;
        end -= 1;
        res += ((totalsum(start, end)) * l); res %= mod;
        l++;
    }
    res += ((totalsum(pow(10, l - 1), R)) * l) % mod;
    res %= mod;
    cout << res << endl;
    return 0;
}
