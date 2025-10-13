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

    vector<ll> factor;
    set<ll> visited;
    queue<ll> q;
    q.push(1);
    visited.insert(1);
    while (!q.empty()) {
        ll n = q.front();
        q.pop();
        for (int i = 2; i < 7; ++i) {
            if (visited.find(n * i) != visited.end()) continue;
            if (N % (n * i) != 0) continue;
            factor.push_back(n * i);
            visited.insert(n * i);
            q.push(n * i);
        }
    }

    sort(factor.begin(), factor.end());

    ll inverse5 = inverse(5);

    map<ll, ll> p;
    p[1] = 1;

    for (ll f : factor) {
        ll res = 0;
        for (int i = 2; i < 7; ++i) {
            if (f % i == 0 && N % (f / i) == 0) {
                res += p[f / i];
                res %= mod;
            }
        }
        res *= inverse5;
        res %= mod;
        p[f] = res;
    }

    cout << p[N] << endl;
    return 0;
}
