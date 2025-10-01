#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)
ll mod = 1e9 + 7;

ll totalsum(ll a, ll b) {
    // aからbまでの和を返す。
    a %= mod;
    b %= mod;
    return ((((a + b) % mod) * ((b - a + 1 + mod) % mod)) % mod) / 2;
}

int main() {
    // 入力
    ll L, R;
    cin >> L >> R;

    // それぞれの桁数を調べる。
    int l = 1;
    while (L >= pow(10, l)) l++;
    int r = 1;
    while (R >= pow(10, r)) r++;

    ll res = 0;
    if (l == r) {
        res += (totalsum(L, R) * l) % mod;
        cout << res << endl;
        return 0;
    }

    res += (totalsum(L, pow(10, l) - 1) * l) % mod;
    l++;
    while (l < r) {
        res += (((totalsum(pow(10, l - 1), pow(10, l) - 1))) * l) % mod;
        l++;
    }
    res += ((totalsum(pow(10, l - 1), R)) * l) % mod;

    cout << res << endl;
    return 0;
}
