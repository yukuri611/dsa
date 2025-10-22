#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

vector<ll> factors;

void findFactor(ll n) {
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            factors.push_back(i);
            if (n / i != i) {
                factors.push_back(n / i);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll K;
    cin >> K;
    findFactor(K);
    sort(factors.begin(), factors.end());

    int sz = factors.size();
    ll res = 0;
    rep(i, sz) {
        for (int j = i; j < sz; ++j) {
            ll a = factors[i], b = factors[j];
            if (K / a < b) continue;
            if (K % (a * b) != 0) continue;
            ll c = K / (a * b);
            if (c < b) continue;
            res++;
        }
    }

    cout << res << endl;
    return 0;
}
