#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)
ll mod = 1e9 + 7;

ll power(ll a, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    ll N, K;
    cin >> N >> K;
    if (N == 1) {
        ll res = K;
        cout << res << endl;
        return 0;
    }
    ll res = (((K * (K - 1)) % mod) * power(K - 2, N - 2)) % mod;
    cout << res << endl;
    return 0;
}
