#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

int main() {
    ll K;
    cin >> K;

    vector<ll> Factor;

    for (ll i = 1; i * i <= K; ++i) {
        if (K % i == 0) {
            Factor.push_back(i);
            if (i != K / i) Factor.push_back(K / i);
        }
    }

    sort(Factor.begin(), Factor.end());

    ll N = Factor.size();
    ll res = 0;
    rep(i, N) {
        ll a = Factor[i];
        for (int j = i; j < N; ++j) {
            ll b = Factor[j];
            if (((K / a) % b) != 0) continue;
            ll c = (K / a) / b;
            if (c < b) break;
            res++;
        }
    }

    cout << res << endl;
    return 0;
}
